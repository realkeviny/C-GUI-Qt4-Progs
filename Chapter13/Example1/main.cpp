#include <iostream>
#include <Q>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMARIADB");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("ducati");
    db.setUserName("root");
    db.setPassword("123456");

    QSqlTableModel model;
    model.setTable("scooter");
    model.setFilter("id=11");
    model.select();
    if(model.rowCount()==1)
    {
        model.removeRows(0, 1);
        model.submitAll();
    }
    //int row = 0;
    //model.insertRows(row, 1);
    //model.setData(model.index(row, 0), 11);
    //model.setData(model.index(row, 1), "BMW S1000RRE");
    //model.setData(model.index(row, 2), 36);
    //model.setData(model.index(row, 3), 42);
    //model.setData(model.index(row, 4), 121);
    //model.setData(model.index(row, 5), "Quick,Slient and Comfortable");
    //model.submitAll();

    db.close();
    return 0;
}
