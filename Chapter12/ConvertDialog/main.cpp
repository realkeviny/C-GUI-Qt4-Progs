#include "ConvertDialog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConvertDialog w;
    w.show();
    return a.exec();
}
