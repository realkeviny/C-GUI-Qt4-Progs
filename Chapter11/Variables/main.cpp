#include <QtCore/QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QString str = "User: ";
    //QString userName = "Kelf";
    //str.append(userName);
    //str.append("\n");

    //str.sprintf("%s %.lf%%", "perfect competition", 100.0);
    //str = QString("%1 %2 (%3s~%4s)").arg("permissive").arg("society").arg(1950).arg(1970);

    //str = QString::number(59.6);
    //bool ok;
    //double d = str.toDouble(&ok);

    QString str = "     BOB \t THE  \n DOG \n";
    //qDebug() << str.trimmed();
    //str.remove(2, 6);
    //str.insert(2, "sunny");
    //str.replace(2, 6, "sunny");
    //int i = str.indexOf("middle");
    return a.exec();
}
