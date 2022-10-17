#include "ViewPortWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ViewPortWindow w;
    w.show();
    return a.exec();
}
