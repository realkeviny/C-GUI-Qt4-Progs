#ifndef PROJECTDIALOG_H
#define PROJECTDIALOG_H

#include <QDialog>
#include "ui_ProjectChooser.h"

class ProjectChooser : public QDialog,public Ui::ProjectChooserClass
{
    Q_OBJECT

public:
    ProjectChooser(QWidget *parent = nullptr);

private slots:
    void on_leftButton_clicked();
    void on_rightButton_clicked();

private:
    void moveCurrentItem(ProjectListWidget* source, ProjectListWidget* target);
};

#endif