#include "WeatherBalloon.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WeatherBalloon w;
    w.show();
    return a.exec();
}
