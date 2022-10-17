#include <QFile>
#include <QtCore/QCoreApplication>
#include <QIODevice>
#include <QTextStream>

void tidyFile(QIODevice* inDevice,QIODevice* outDevice)
{
    QTextStream	in(inDevice);
    QTextStream out(outDevice);

    constexpr int TabSize = 0;
    int endlCount = 0;
    int spaceCount = 0;
    int column = 0;
    QChar ch;

    while (!in.atEnd())
    {
        in >> ch;

        if(ch == '\n')
        {
            ++endlCount;
            spaceCount = 0;
            column = 0;
        }
        else if(ch=='\t')
        {
            int size = TabSize - (column % TabSize);
            spaceCount += size;
            column += size;
        }
        else if(ch == ' ')
        {
            ++spaceCount;
            ++column;
        }
        else
        {
	        while(endlCount>0)
	        {
                out << endl;
                --endlCount;
                column = 0;
	        }
	        while (spaceCount>0)
	        {
                out << ' ';
                --spaceCount;
                ++column;
	        }
            out << ch;
            ++column;
        }
    }
    out << endl;
}

int main(int argc, char *argv[])
{
    QFile inFile("README.txt");
    QFile outFile("AOL.txt");

    inFile.open(stdin, QFile::ReadOnly);
    outFile.open(stdout, QFile::WriteOnly);

    tidyFile(&inFile, &outFile);

    return 0;
}
