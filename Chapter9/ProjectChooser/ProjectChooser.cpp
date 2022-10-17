#include "ProjectChooser.h"


ProjectChooser::ProjectChooser(QWidget *parent)
    : ::QDialog(parent)
{
    setupUi(this);


    projectA->addItem("Giosue Carducci");
    projectA->addItem("Eyvind Johnson");
    projectA->addItem("Sally Prudhomme");
    projectA->addItem("Henryk Sienkiewicz");
    projectA->addItem("Carl Spitteler");
    projectA->addItem("Rabindranath Tagore");
    projectA->addItem("Kawabata Yasunari");
    projectA->addItem("David R. O'Hallaron");

    projectB->addItem("Rudolf Eucken");
    projectB->addItem("Anatole France");
    projectB->addItem("Rudyard Kipling");
    projectB->addItem("Thomas Mann");
    projectB->addItem("Eugene O'Neill");
    projectB->addItem("Sigrid Undset");
    projectB->addItem("Randal E.Bryant");
}

void ProjectChooser::on_leftButton_clicked()
{
    moveCurrentItem(projectB, projectA);
    connect(leftButton, SIGNAL(clicked()), projectB, SLOT(on_leftButton_clicked()));
}


void ProjectChooser::on_rightButton_clicked()
{
    moveCurrentItem(projectA, projectB);
    connect(rightButton, SIGNAL(clicked()), projectA, SLOT(on_rightButton_clicked()));
}

void ProjectChooser::moveCurrentItem(ProjectListWidget* source, ProjectListWidget* target)
{
	if(source->currentItem())
	{
        QListWidgetItem* newItem = source->currentItem()->clone();
        target->addItem(newItem);
        target->setCurrentItem(newItem);
        delete source->currentItem();
	}
}
