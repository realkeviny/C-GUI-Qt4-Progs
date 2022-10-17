#include <QApplication>
#include <iostream>
#include "Tetrahedrone.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (!QGLFormat::hasOpenGL())
    {
        std::cerr << "This system has no OpenGL support" << std::endl;
        return 1;
    }

    Tetrahedrone tetrahedrone;
    tetrahedrone.setWindowTitle(QObject::tr("Tetrahedron"));
    tetrahedrone.resize(300, 300);
    tetrahedrone.show();
    return app.exec();
}
