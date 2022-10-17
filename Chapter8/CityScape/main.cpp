#include "CityScape.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CityScape w;
    w.show();
    return a.exec();
}
