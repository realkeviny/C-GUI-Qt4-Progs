#include "DragExample.h"
#include <QtWidgets>

DragExample::DragExample(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DragExampleClass())
{
    ui->setupUi(this);

    textEdit = new QTextEdit;
    setCentralWidget(textEdit);

    textEdit->setAcceptDrops(false);
    setAcceptDrops(true);

    setWindowTitle(tr("Text Editor"));
}

DragExample::~DragExample()
{
    delete ui;
}

void DragExample::dragEnterEvent(QDragEnterEvent* event)
{
    if (event->mimeData()->hasFormat("text/uri-list"))
    {
        event->acceptProposedAction();
    }
}

void DragExample::dropEvent(QDropEvent* event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if(urls.isEmpty())
    {
	    return;
    }

    QString fileName = urls.first().toLocalFile();

    if(fileName.isEmpty())
    {
	    return;
    }

    if(readFile(fileName))
    {
        setWindowTitle(tr("%1 - %2").arg(fileName).arg(tr("Drag File")));
    }
}


bool DragExample::readFile(const QString& fileName)
{
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly))
    {
        return false;
    }
    QTextStream in(&file);
    
    textEdit->setText(in.readAll());
    return true;
}
