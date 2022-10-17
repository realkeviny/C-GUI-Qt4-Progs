#ifndef BOOLEANMODEL_H
#define BOOLEANMODEL_H

#include <QAbstractItemModel>

class Node;

class BooleanModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    BooleanModel(QObject *parent = nullptr);
    ~BooleanModel();

    void setRootNode(Node* node);
    QModelIndex index(int row, int column, const QModelIndex& parent) const override;
    QModelIndex parent(const QModelIndex& child) const override;

    int rowCount(const QModelIndex& parent) const override;
    int columnCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    Node* nodeFromIndex(const QModelIndex& index) const;
    Node* rootNode;
};

#endif