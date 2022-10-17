#include <QtCore/QCoreApplication>
#include <QImage>
#include <iostream>
#include <QMap>
#include <QFile>

void WriteFile()
{
    QImage image("Ford.jpg");

    QMap<QString, QColor> map;
    map.insert("red", Qt::red);
    map.insert("green", Qt::green);
    map.insert("blue", Qt::blue);

    QFile file("facts.dat");
    if (!file.open(QIODevice::WriteOnly))
    {
        std::cerr << "Cannot open file for writing: " << qPrintable(file.errorString()) << std::endl;
    }
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_15);

    out << quint32(0x12345678) << image << map;
}

void ReadFile()
{
    quint32 n;
    QImage image;
    QMap<QString, QColor> map;

    QFile file("facts.dat");
    if(!file.open(QIODevice::ReadOnly))
    {
        std::cerr << "Cannot open file for reading: " << qPrintable(file.errorString()) << std::endl;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_15);

    in >> n >> image >> map;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ReadFile();

    return a.exec();
}
