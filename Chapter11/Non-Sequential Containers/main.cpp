#include <QtCore/QCoreApplication>
#include <QMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, int> map;
    //map.insert("eins", 1);
    //map.insert("sieben", 7);
    //map.insert("dreiundzwanzig", 23);

    map["eins"] = 1;
    map["sieben"] = 7;
    map["dreiundzwanzig"] = 23;


    int val = map.value("dreiundzwanzig");

    QMultiMap<int, QString> multiMap;
    multiMap.insert(1, "one");
    multiMap.insert(1, "eins");
    multiMap.insert(1, "uno");
    QList<QString> vals = multiMap.values(1);
    return a.exec();
}
