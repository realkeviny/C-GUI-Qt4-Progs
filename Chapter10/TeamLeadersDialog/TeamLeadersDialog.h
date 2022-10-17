#ifndef TEAMLEADERSDIALOG_H
#define TEAMLEADERSDIALOG_H

#include <QDialog>

class QStringListModel;
class QListView;
class QDialogButtonBox;

class TeamLeadersDialog : public QDialog
{
    Q_OBJECT

public:
    TeamLeadersDialog(const QStringList & leaders,QWidget *parent = nullptr);

    QStringList leaders() const;

private slots:
    void insert();
    void del();

private:
    QListView* listView;
    QDialogButtonBox* buttonBox;
    QStringListModel* model;
};

#endif