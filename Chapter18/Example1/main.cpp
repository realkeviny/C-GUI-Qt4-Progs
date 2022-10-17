#include <iostream>
#include <QtCore>
#include <QTextCodec>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPushButton button(QObject::tr("Hello Qt!"));
    QCoreApplication::translate("Global Stuff", "Hello Qt!");
    button.show();

    return a.exec();
}
