#include "IconEditor.h"
#include <QApplication>
#include <QScrollArea>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IconEditor* iconEditor = new IconEditor;
    iconEditor->setIconImage(QImage(":/IconEditor/image/Song.png"));

    QScrollArea scrollArea;
    scrollArea.setWidget(iconEditor);
    scrollArea.viewport()->setBackgroundRole(QPalette::Dark);
    scrollArea.viewport()->setAutoFillBackground(true);
    scrollArea.setWindowTitle(QObject::tr("Icon Editor"));

    scrollArea.show();
    return a.exec();
}
