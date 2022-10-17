#include <QtCore/QCoreApplication>
#include <QLinkedList>

class Movie
{
public:
    Movie(const QString& title = "", int duration = 0);

    void setTitle(const QString& title)
    {
        myTitle = title;
    }
    QString title() const
    {
        return myTitle;
    }
    void setDuration(int duration)
    {
        myDuration = duration;
    }
    int duration() const
    {
        return myDuration;
    }

private:
    QString myTitle;
    int myDuration;
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Raw Vector
    //QVector<double> vect(3);
    //vect[0] = 1.0;
    //vect[1] = 0.540302;
    //vect[2] = -0.416147;

    //append
    //vect.append(1.0);
    //vect.append(0.540302);
    //vect.append(-0.416147);

    //stream
    //vect << 1.0 << 0.540302 << -0.416147;

    //double sum = 0.0;
    //for (int i = 0; i < vect.count(); ++i)
    //{
    //    sum += vect[i];
	//}

   /* QLinkedList<QString> list;
    list.append("Clash");
    list.append("Ramones");*/

    
    return a.exec();
}
