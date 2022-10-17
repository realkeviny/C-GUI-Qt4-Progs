#ifndef SAXHANDLER_H
#define SAXHANDLER_H

#include 

class QTreeWidget;
class QTreeWidgetItem;

class SaxHandler : public QObject,public QXmlDefaultHandler
{
    Q_OBJECT

public:
    SaxHandler(QTreeWidget* tree);

    bool readFile(const QString& fileName);

protected:
    boo
    bool endElement(const QString& namespaceURI, const QString& localName, const QString& qName) override;
    bool characters(const QString& ch) override;
    bool fatalError(const QXmlParseException& exception) override;
private:
    QTreeWidget* treeWidget;
    QTreeWidgetItem* currentItem;
    QString currentText;
};

#endif