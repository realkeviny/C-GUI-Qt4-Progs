#include "HexSpinBox.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HexSpinBox w;
    w.show();
    return a.exec();
}
