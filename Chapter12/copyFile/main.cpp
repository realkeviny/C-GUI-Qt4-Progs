#include <iostream>
#include <QFile>
#include <QtCore/QCoreApplication>


bool copyFile(const QString& source,const QString& dest)
{
    QFile sourceFile(source);
    if(!sourceFile.open(QIODevice::ReadOnly))
    {
        return false;
    }

    QFile destFile(dest);
    if(!destFile.open(QIODevice::WriteOnly))
    {
        return false;
    }

    destFile.write(sourceFile.readAll());

    return sourceFile.error() == QFile::NoError && destFile.error() == QFile::NoError;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    bool ret = copyFile("facts.dat", "concrete.oss");
    std::cout << ret << std::endl;
    return a.exec();
}
