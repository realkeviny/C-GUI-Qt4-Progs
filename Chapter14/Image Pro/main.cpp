#include "ImagePro.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImagePro w;
    w.resize(400, 300);
    w.show();
    return a.exec();
}
