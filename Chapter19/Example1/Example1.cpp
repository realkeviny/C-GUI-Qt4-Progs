#include "Example1.h"

Example1::Example1(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

    //qApp->setStyleSheet("QLineEdit {background-color: blue; }");
    //ui.lineEdit->setStyleSheet("background-color : Green;");
    nameLineEdit->setProperty("mandatoryField", true);
    genderComboBox->setProperty("mandatoryField", true);
    ageSpinBox->setProperty("mandatoryField", true);
    
}

Example1::~Example1()
{}
