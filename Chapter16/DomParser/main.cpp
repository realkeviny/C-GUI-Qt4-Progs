#include "DomParser.h"
#include <QtWidgets>
#include <iostream>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QStringList args = QApplication::arguments();

	if(args.count() < 2)
	{
		std::cerr << "Usage: domparser file.xml" << std::endl;
		return 1;
	}

	QStringList labels;
	labels << QObject::tr("Terms") << QObject::tr("Pages");

	QTreeWidget treeWidget;
	treeWidget.setHeaderLabels(labels);
	treeWidget.header()->setSectionResizeMode(QHeaderView::Stretch);
	treeWidget.setWindowTitle(QObject::tr("DOM Parser"));
	treeWidget.show();

	DomParser parser(&treeWidget);
	for (int i = 0; i < args.count(); ++i)
	{
		parser.readFile(args[i]);
	}

	return app.exec();
}
