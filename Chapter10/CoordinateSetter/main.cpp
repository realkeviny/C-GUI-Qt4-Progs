#include "CoordinateSetter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QList<QPointF> coordinates;
    coordinates << QPointF(0.0, 0.98)
        << QPointF(1.2, 2.24)
        << QPointF(3.4, 4.7)
        << QPointF(5.2, 7.43)
        << QPointF(8.6, 9.33)
        << QPointF(10.43, 43.36);
    CoordinateSetter coordinateSetter(&coordinates);
    coordinateSetter.show();

    return a.exec();
}
