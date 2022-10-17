#include <iostream>
#include <QtCore/QCoreApplication>
#include <QDir>
#include <QImageReader>

qlonglong imageSpace(const QString& path)
{
    QDir dir(path);
    qlonglong size = 0;

    QStringList filters;
    foreach(QByteArray format,QImageReader::supportedImageFormats())
    {
        filters += "*." + format;
    }
    foreach(QString file,dir.entryList(filters,QDir::Files))//文件名过滤器列表以及所要指定的条目类型
    {
        size += QFileInfo(dir, file).size();
    }
    foreach(QString subDir,dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot))//获取子目录
    {
        size += imageSpace(path + QDir::separator() + subDir);
    }
    return size;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList args = QCoreApplication::arguments();

    QDir dir;
    QString path = dir.filePath("E:/Pic");
    if(args.count() > 1)
    {
        path = args[1];
    }

    std::cout << "Space used by images in: " << qPrintable(path) << " and its subdirectories is " << (imageSpace(path) / 1024) << "KB" << std::endl;
    return 0;
}
