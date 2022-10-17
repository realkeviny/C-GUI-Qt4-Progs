#include "Hello.h"
#include <QtWidgets/QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel* label = new QLabel("<h2><i>Hello</i>"
        "<font color=blue> Qt!</font></h2>");
    label->show();
    return a.exec();
}
