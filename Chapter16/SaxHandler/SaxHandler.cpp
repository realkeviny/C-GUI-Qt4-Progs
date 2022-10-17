#include "SaxHandler.h"

#include <iostream>
#include <QtWidgets>
#include <QtXml>


SaxHandler::SaxHandler(QTreeWidget* tree)
{
	treeWidget = tree;
}

bool SaxHandler::readFile(const QString& fileName)
{
	currentItem = 0;

	QFile file(fileName);
	QXmlStreamReader reader();
	reader.setContentHandler(this);
	reader.setErrorHandler(this);
	return reader.parse(inputSource);
}



bool SaxHandler::characters(const QString& ch)
{
	currentText += ch;
	return true;
}

bool SaxHandler::endElement(const QString& /*namespaceURI*/, const QString& /*localName*/, const QString& qName)
{
	if(qName == "entry")
	{
		currentItem = currentItem->parent();
	}
	else if(qName=="page")
	{
		if(currentItem)
		{
			QString allPages = currentItem->text(1);
			if(!allPages.isEmpty())
			{
				allPages += ", ";
			}
			allPages += currentText;
			currentItem->setText(1, allPages);
		}
	}
	return true;
}

bool SaxHandler::fatalError(const QXmlParseException& exception)
{
	std::cerr << "Parse Error at line " << exception.lineNumber() << ", " << "column " << exception.columnNumber() << ": " << qPrintable(exception.message()) << std::endl;
	return false;
}

