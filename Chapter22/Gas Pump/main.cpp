#include "GasPump.h"
#include "Scripting.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QStringList args = QApplication::arguments();
    if (args.count() >= 3 && args[1] == "-script")
    {
        runScript(args[2], args.mid(3));
        return 0;
    }
    else if (args.count() == 1)
    {
        GasPump pump;
        pump.show();
        pump.resize(700, 800);
        return app.exec();
    }
    else
    {
        std::cerr << "Usage: gaspump [-script myscript.js <arguments>]" << std::endl;
        return 1;
    }
}
