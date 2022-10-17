#include <QtCore/QCoreApplication>
#include <QLinkedList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QStringList list;
    //list << "Emma" << "Karl" << "James" << "Mariette";

    //QStringList::iterator i = qFind(list.begin(), list.end(), "Karl");
    //QStringList::iterator j = qFind(list.begin(), list.end(), "Petra");

    QVector<int> vect(10);
    qFill(vect.begin(), vect.begin() + 5, 1009);
    qFill(vect.end()-5, vect.end(), 2013);
	return a.exec();
}
