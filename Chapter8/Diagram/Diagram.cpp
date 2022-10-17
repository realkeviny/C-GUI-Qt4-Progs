#include "Diagram.h"
#include "Link.h"
#include "Node.h"
#include "PropertiesDialog.h"
#include <QGraphicsView>

Diagram::Diagram(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    scene = new QGraphicsScene(0, 0, 600, 500);

    view = new QGraphicsView;
    view->setScene(scene);
    view->setDragMode(QGraphicsView::RubberBandDrag);
    view->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    view->setContextMenuPolicy(Qt::ActionsContextMenu);
    setCentralWidget(view);

    minZ = 0;
    maxZ = 0;
    seqNumber = 0;

    createActions();
    createMenus();
    createToolBars();

    connect(scene, SIGNAL(selectionChanged()), this, SLOT(updateActions()));

    setWindowTitle(tr("Diagram"));
    updateActions();
}

void Diagram::addNode()
{
    Node* node = new Node;
    node->setText(tr("Node %1").arg(seqNumber + 1));
    setupNode(node);
}

void Diagram::setupNode(Node* node)
{
    node->setPos(QPoint(80 + (100 * (seqNumber % 5)), 80 + (50 * ((seqNumber / 5) % 7))));
    scene->addItem(node);
    ++seqNumber;

    scene->clearSelection();
    node->setSelected(true);
    bringToFront();
}

void Diagram::bringToFront()
{
    ++maxZ;
    setZValue(maxZ);
}

void Diagram::sendToBack()
{
    --minZ;
    setZValue(minZ);
}

void Diagram::createActions()
{
    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    addNodeAction = new QAction(tr("Add &Node"), this);
    addNodeAction->setIcon(QIcon(":/images/icons/Node.png"));
    addNodeAction->setShortcut(tr("Ctrl+N"));
    connect(addNodeAction, SIGNAL(triggered()), this, SLOT(addNode()));

    addLinkAction = new QAction(tr("Add &Link"), this);
    addLinkAction->setIcon(QIcon(":/images/icons/Link.png"));
    addLinkAction->setShortcut(tr("Ctrl+L"));
    connect(addLinkAction, SIGNAL(triggered()), this, SLOT(addLink()));

    deleteAction = new QAction(tr("&Delete"), this);
    deleteAction->setIcon(QIcon(":/images/icons/Delete.png"));
    deleteAction->setShortcut(tr("Del"));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(del()));

    cutAction = new QAction(tr("Cu&t"), this);
    cutAction->setIcon(QIcon(":/images/icons/Cut.png"));
    cutAction->setShortcut(tr("Ctrl+X"));
    connect(cutAction, SIGNAL(triggered()), this, SLOT(cut()));

    copyAction = new QAction(tr("&Copy"), this);
    copyAction->setIcon(QIcon(":/images/icons/Copy.png"));
    copyAction->setShortcut(tr("Ctrl+C"));
    connect(copyAction, SIGNAL(triggered()), this, SLOT(copy()));

    pasteAction = new QAction(tr("&Paste"), this);
    pasteAction->setIcon(QIcon(":/images/icons/Paste.png"));
    pasteAction->setShortcut(tr("Ctrl+V"));
    connect(pasteAction, SIGNAL(triggered()), this, SLOT(paste()));

    bringToFrontAction = new QAction(tr("Bring to &Front"), this);
    bringToFrontAction->setIcon(QIcon(":/images/icons/BringToFront.png"));
    connect(bringToFrontAction, SIGNAL(triggered()), this, SLOT(bringToFront()));

    sendToBackAction = new QAction(tr("&Send to Back"), this);
    sendToBackAction->setIcon(QIcon(":/images/icons/SendToBack.png"));
    connect(sendToBackAction, SIGNAL(triggered()), this, SLOT(sendToBack()));

    propertiesAction = new QAction(tr("P&roperties.."), this);
    connect(propertiesAction, SIGNAL(triggered()), this, SLOT(properties()));
}

void Diagram::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(addNodeAction);
    editMenu->addAction(addLinkAction);
    editMenu->addAction(deleteAction);
    editMenu->addSeparator();
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addSeparator();
    editMenu->addAction(bringToFrontAction);
    editMenu->addAction(sendToBackAction);
    editMenu->addSeparator();
    editMenu->addAction(propertiesAction);
}

void Diagram::createToolBars()
{
    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(addNodeAction);
    editToolBar->addAction(addLinkAction);
    editToolBar->addAction(deleteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(bringToFrontAction);
    editToolBar->addAction(sendToBackAction);
}

void Diagram::setZValue(int z)
{
    Node* node = selectedNode();
    if(node)
    {
        node->setZValue(z);
    }
}

Node* Diagram::selectedNode() const
{
    QList<QGraphicsItem*> items = scene->selectedItems();
    if(items.count()==1)
    {
        return dynamic_cast<Node*>(items.first());
    }
    else
    {
        return nullptr;
    }
}

Link* Diagram::selectedLink() const
{
    QList<QGraphicsItem*> items = scene->selectedItems();
    if (items.count() == 1)
    {
        return dynamic_cast<Link*>(items.first());
    }
    else
    {
        return nullptr;
    }
}

Diagram::NodePair Diagram::selectedNodePair() const
{
    QList<QGraphicsItem*> items = scene->selectedItems();

    if (items.count() == 2)
    {
        Node* first = dynamic_cast<Node*>(items.first());
        Node* second =  dynamic_cast<Node*>(items.last());
        if (first && second)
            return NodePair(first, second);
    }
    return NodePair();
}


void Diagram::addLink()
{
    NodePair nodes = selectedNodePair();
    if(nodes == NodePair())
    {
        return;
    }

    Link* link = new Link(nodes.first, nodes.second);
    scene->addItem(link);
}

void Diagram::del()
{
    QList<QGraphicsItem*> items = scene->selectedItems();
    QMutableListIterator<QGraphicsItem*> i(items);
    while(i.hasNext())
    {
        Link* link = dynamic_cast<Link*>(i.next());
        if(link)
        {
            delete link;
            i.remove();
        }
    }

    qDeleteAll(items);
}

void Diagram::properties()
{
    Node* node = selectedNode();
    Link* link = selectedLink();

    if(node)
    {
        PropertiesDialog dialog(node, this);
        dialog.exec();
    }
    else if(link)
    {
        QColor color = QColorDialog::getColor(link->color(), this);
        if(color.isValid())
        {
            link->setColor(color);
        }
    }
}

void Diagram::cut()
{
    Node* node = selectedNode();
    if (!node)
        return;

    copy();
    delete node;
}

void Diagram::copy()
{
    Node* node = selectedNode();
    if (!node)
        return;

    QString str = QString("Node %1 %2 %3 %4").arg(node->textColor().name()).arg(node->outlineColor().name()).arg(node->backgroundColor().name()).arg(node->text());
    QApplication::clipboard()->setText(str);
}

void Diagram::paste()
{
    QString str = QApplication::clipboard()->text();
    QStringList parts = str.split(" ");
    if(parts.count() >=5&&parts.first()=="Node")
    {
        Node* node = new Node;
        node->setText(QStringList(parts.mid(4)).join(" "));
        node->setTextColor(QColor(parts[1]));
        node->setOutlineColor(QColor(parts[2]));
        node->setBackgroundColor(QColor(parts[3]));
        setupNode(node);
    }
}

void Diagram::updateActions()
{
    bool hasSelection = !scene->selectedItems().isEmpty();
    bool isNode = (selectedNode() != nullptr);
    bool isNodePair = (selectedNodePair() != NodePair());

    cutAction->setEnabled(isNode);
    copyAction->setEnabled(isNode);
    addLinkAction->setEnabled(isNodePair);
    deleteAction->setEnabled(hasSelection);
    bringToFrontAction->setEnabled(isNode);
    sendToBackAction->setEnabled(isNode);
    propertiesAction->setEnabled(isNode);

    foreach(QAction* action,view->actions())
    {
        view->removeAction(action);
    }

    foreach(QAction* action,editMenu->actions())
    {
	    if(action->isEnabled())
	    {
            view->addAction(action);
	    }
    }
}
