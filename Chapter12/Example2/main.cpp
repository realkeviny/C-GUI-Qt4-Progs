#include <QtCore/QCoreApplication>

class Painting
{
public:
    Painting() { myYear = 0; }
    Painting(const QString& title, const QString& artist, int year)
    {
        myTitle = title;
        myArtist = artist;
        myYear = year;
    }
    void setTitle(const QString& title)
    {
        myTitle = title;
    }
    QString title() const
    {
        return myTitle;
    }
    void setArtist(const QString& artist)
    {
        myArtist = artist;
    }
    QString artist() const
    {
        return myArtist;
    }
    void setYear(int year)
    {
        myYear = year;
    }
    int year() const
    {
        return myYear;
    }

private:
    QString myTitle;
    QString myArtist;
    int myYear;
};

QDataStream& operator<< (QDataStream& out, const Painting& painting)
{
    out << painting.title() << painting.artist() << static_cast<quint32>(painting.year());
    return out;
}

QDataStream& operator>>(QDataStream& in, Painting& painting)
{
    QString title;
    QString artist;
    quint32 year;

    in >> title >> artist;
    in >> year;
    painting = Painting(title, artist, year);
}





int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
