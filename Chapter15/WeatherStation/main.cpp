#include "WeatherStation.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WeatherStation w;
    w.show();
    return a.exec();
}
