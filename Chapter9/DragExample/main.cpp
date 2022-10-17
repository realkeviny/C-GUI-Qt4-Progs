#include "DragExample.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DragExample w;
    w.show();
    return a.exec();
}
