#ifndef DIRECTORYVIEWER_H
#define DIRECTORYVIEWER_H

#include <QDialog>

class QTreeView;
class QDirModel;
class QDialogButtonBox;

class DirectoryViewer : public QDialog
{
    Q_OBJECT

public:
    DirectoryViewer(QWidget *parent = nullptr);

private slots:
    void createDirectory();
    void remove();

private:
    QTreeView* treeView;
    QDirModel* model;
    QDialogButtonBox* buttonBox;
};

#endif