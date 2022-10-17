#ifndef COLORNAMESDIALOG_H
#define COLORNAMESDIALOG_H

#include <QDialog>

class QStringListModel;
class QSortFilterProxyModel;
class QListView;
class QLabel;
class QLineEdit;
class QComboBox;

class ColorNamesDialog : public QDialog
{
    Q_OBJECT

public:
    ColorNamesDialog(QWidget *parent = nullptr);

private slots:
    void reapplyFilter();

private:
    QStringListModel* sourceModel;
    QSortFilterProxyModel* proxyModel;
    QListView* listView;
    QLabel* filterLabel;
    QLabel* syntaxLabel;
    QLineEdit* filterLineEdit;
    QComboBox* syntaxComboBox;
};

#endif