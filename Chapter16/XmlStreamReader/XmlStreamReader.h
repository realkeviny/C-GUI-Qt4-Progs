#pragma once

#include <QMainWindow>
#include <QXmlStreamReader>

class QTreeWidget;
class QTreeWidgetItem;

class XmlStreamReader : public QMainWindow
{
    Q_OBJECT

public:
    XmlStreamReader(QTreeWidget* tree);

    bool readFile(const QString& fileName);

private:
    void readBookIndexElement();
    void readEntryElement(QTreeWidgetItem* parent);
    void readPageElement(QTreeWidgetItem* parent);
    void skipUnknownElement();

    QTreeWidget* treeWidget;
    QXmlStreamReader reader;
};
