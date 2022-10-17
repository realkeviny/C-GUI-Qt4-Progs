#include "Teapots.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    if (!QGLFormat::hasOpenGL())
    {
        std::cerr << "This system has no OpenGL support!" << std::endl;
        return 1;
    }

    Teapots teapots;
    teapots.setWindowTitle(QObject::tr("Teapots"));
    teapots.resize(400, 400);
    teapots.show();
    return app.exec();
}
