#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <QMainWindow>
#include <QPair>
#include "ui_Diagram.h"

class QAction;
class QGraphicsItem;
class QGraphicsScene;
class QGraphicsView;
class Link;
class Node;

class Diagram : public QMainWindow
{
    Q_OBJECT

public:
    Diagram(QWidget *parent = nullptr);

private slots:
    void addNode();
    void addLink();
    void del();
    void cut();
    void copy();
    void paste();
    void bringToFront();
    void sendToBack();
    void properties();
	void updateActions();
private:
    Ui::DiagramClass ui;

    using NodePair = QPair<Node*, Node*>;

    void createActions();
    void createMenus();
    void createToolBars();
    void setZValue(int z);
    void setupNode(Node* node);
    Node* selectedNode() const;
    Link* selectedLink() const;
    NodePair selectedNodePair() const;

    QMenu* fileMenu;
    QMenu* editMenu;
    QToolBar* editToolBar;
    QAction* exitAction;
    QAction* addNodeAction;
    QAction* addLinkAction;
    QAction* deleteAction;
    QAction* cutAction;
    QAction* copyAction;
    QAction* pasteAction;
    QAction* bringToFrontAction;
    QAction* sendToBackAction;
    QAction* propertiesAction;

    QGraphicsScene* scene;
    QGraphicsView* view;

    int minZ;
    int maxZ;
    int seqNumber;
};

#endif
