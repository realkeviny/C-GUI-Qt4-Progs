#include "ProjectChooser.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProjectChooser w;
    w.show();
    return a.exec();
}
