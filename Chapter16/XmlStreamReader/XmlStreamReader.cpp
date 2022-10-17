#include "XmlStreamReader.h"

#include <iostream>
#include <QtWidgets>
#include <QtXml>

XmlStreamReader::XmlStreamReader(QTreeWidget* tree)
{
	treeWidget = tree;
}

bool XmlStreamReader::readFile(const QString& fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		std::cerr << "Error: Cannot read file " << qPrintable(fileName) << ": " << qPrintable(file.errorString()) << std::endl;
		return false;
	}

	reader.setDevice(&file);

	reader.readNext();
	while (!reader.atEnd())
	{
		if (reader.isStartElement())
		{
			if (reader.name() == "bookindex")
			{
				readBookIndexElement();
			}
			else
			{
				reader.raiseError(QObject::tr("Not a bookindex file"));
			}
		}
		else
		{
			reader.readNext();
		}
	}

	file.close();
	if (reader.hasError())
	{
		std::cerr << "Error: Failed to parse file "
			<< qPrintable(fileName) << ": " << qPrintable(reader.errorString()) << std::endl;
		return false;
	}
	else if (file.error() != QFile::NoError)
	{
		std::cerr << "Error: Cannot read file "
			<< qPrintable(fileName) << ": " << qPrintable(reader.errorString()) << std::endl;
		return false;
	}
	return true;
}

void XmlStreamReader::readBookIndexElement()
{
	Q_ASSERT(reader.isStartElement() && reader.name() == "bookindex");
	reader.readNext();
	while (!reader.atEnd())
	{
		if (reader.isEndElement())
		{
			reader.readNext();
			break;
		}

		if (reader.isStartElement())
		{
			if (reader.name() == "entry")
			{
				readEntryElement(treeWidget->invisibleRootItem());
			}
			else
			{
				skipUnknownElement();
			}
		}
		else
		{
			reader.readNext();
		}
	}
}

void XmlStreamReader::readEntryElement(QTreeWidgetItem* parent)
{
	Q_ASSERT(reader.isStartElement() && reader.name() == "entry");
	QTreeWidgetItem* item = new QTreeWidgetItem(parent);
	item->setText(0, reader.attributes().value("term").toString());

	reader.readNext();
	while (!reader.atEnd())
	{
		if (reader.isEndElement())
		{
			reader.readNext();
			break;
		}

		if (reader.isStartElement())
		{
			if (reader.name() == "entry")
			{
				readEntryElement(item);
			}
			else if (reader.name() == "page")
			{
				readPageElement(item);
			}
			else
			{
				skipUnknownElement();
			}
		}
		else
		{
			reader.readNext();
		}
	}
}

void XmlStreamReader::readPageElement(QTreeWidgetItem* parent)
{
	Q_ASSERT(reader.isStartElement() && reader.name() == "page");

	QString page = reader.readElementText();
	if (reader.isEndElement())
	{
		reader.readNext();
	}

	QString allPages = parent->text(1);
	if (!allPages.isEmpty())
	{
		allPages += ", ";
	}
	allPages += page;
	parent->setText(1, allPages);
}

void XmlStreamReader::skipUnknownElement()
{
	Q_ASSERT(reader.isStartElement());
	reader.readNext();
	while (!reader.atEnd())
	{
		if (reader.isEndElement())
		{
			reader.readNext();
			break;
		}

		if (reader.isStartElement())
		{
			skipUnknownElement();
		}
		else
		{
			reader.readNext();
		}
	}
}



