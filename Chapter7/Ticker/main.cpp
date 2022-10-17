#include "Ticker.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ticker w;
    w.setWindowTitle(QObject::tr("Ticker"));
    w.setText(QObject::tr("How long does it take to rush B?"));
    w.show();
    return a.exec();
}
