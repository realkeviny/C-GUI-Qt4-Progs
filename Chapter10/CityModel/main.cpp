#include "CityModel.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList cities;
    cities << "Arvika" << "Boden" << "Eskilstuna" << "Falun"
        << "Filipstad" << "Halmstad" << "Helsingborg" << "Karlstad"
        << "Kiruna" << "Kramfors" << "Motala" << "Sandviken"
        << "Skara" << "Stockholm" << "Sundsvall" << "Trelleborg";

    CityModel cityModel;
    cityModel.setCities(cities);

    QTableView tableView;
    tableView.setModel(&cityModel);
    tableView.setAlternatingRowColors(true);
    tableView.setWindowTitle(QObject::tr("Cities"));
    tableView.show();
    return a.exec();
}