#include "CustomerInfoDialog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomerInfoDialog w;
    w.show();
    return a.exec();
}
