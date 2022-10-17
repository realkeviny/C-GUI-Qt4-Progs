#include "IconEditorPlugin.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IconEditorPlugin w;
    w.show();
    return a.exec();
}
