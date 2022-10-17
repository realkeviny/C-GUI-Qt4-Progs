#include "VowelCube.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (!QGLFormat::hasOpenGL())
    {
        std::cerr << "This system has no OpenGL support" << std::endl;
        return 1;
    }

    VowelCube w;
    w.setWindowTitle(QObject::tr("Vowel Cube"));
    w.setMinimumSize(200, 200);
    w.resize(450, 450);
    w.show();
    return app.exec();
}
