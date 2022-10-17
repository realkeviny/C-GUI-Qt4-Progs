#ifndef DOMPARSER_H
#define DOMPARSER_H

#include <QMainWindow>
class QTreeWidget;
class QDomElement;
class QTreeWidgetItem;

class DomParser : public QMainWindow
{
    Q_OBJECT

public:
    DomParser(QTreeWidget* tree);
    
    bool readFile(const QString& fileName);
private:
    void parseBookindexElement(const QDomElement& element);
    void parseEntryElement(const QDomElement& element, QTreeWidgetItem* parent);
    void parsePageElement(const QDomElement& element, QTreeWidgetItem* parent);

    QTreeWidget* treeWidget;
};

#endif