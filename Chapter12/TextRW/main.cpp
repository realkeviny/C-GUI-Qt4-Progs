#include <iostream>
#include <QtCore/QCoreApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("sf-book.txt");
    if(!file.open(QIODevice::WriteOnly))
    {
        std::cerr << "Cannot open file for writing: " << qPrintable(file.errorString()) << std::endl;
        return -1;
    }

    QTextStream out(&file);
    out << "Thomas M. Disch: " << 334 << endl;
    out << "Denmark" << "Norway" << endl;
    out << showbase << uppercasedigits << hex << 12345678 << endl;
    return a.exec();
}
