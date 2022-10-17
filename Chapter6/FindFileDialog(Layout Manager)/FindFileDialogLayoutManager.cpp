#include "FindFileDialogLayoutManager.h"
#include <QtWidgets>

FindFileDialogLayoutManager::FindFileDialogLayoutManager(QWidget *parent)
    : QDialog(parent)
{
	namedLabel = new QLabel(tr("&Named:"), this);
	namedLineEdit = new QLineEdit(this);
	namedLabel->setBuddy(namedLineEdit);

	lookInLabel = new QLabel(tr("&Look In:"), this);
	lookInLineEdit = new QLineEdit(this);
	lookInLabel->setBuddy(lookInLineEdit);

	subfoldersCheckBox = new QCheckBox(tr("Include SubFolders"), this);

	QStringList labels;
	labels << tr("Name") << tr("In Folder") << tr("Size") << tr("Modified");

	tableWidget = new QTableWidget(this);
	tableWidget->setColumnCount(4);
	tableWidget->setHorizontalHeaderLabels(labels);

	messageLabel = new QLabel(tr("0 files found"), this);
	messageLabel->setFrameShape(QLabel::Panel);
	messageLabel->setFrameShadow(QLabel::Sunken);

	findButton = new QPushButton(tr("&Find"));
	stopButton = new QPushButton(tr("Stop"));
	closeButton = new QPushButton(tr("Close"));
	helpButton = new QPushButton(tr("Help"));

	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

	QGridLayout* leftLayout = new QGridLayout;
	leftLayout->addWidget(namedLabel, 0, 0);
	leftLayout->addWidget(namedLineEdit, 0, 1);
	leftLayout->addWidget(lookInLabel, 1, 0);
	leftLayout->addWidget(lookInLineEdit, 1, 1);
	leftLayout->addWidget(subfoldersCheckBox,2, 0, 1,2);
	leftLayout->addWidget(tableWidget, 3, 0, 1, 2);
	leftLayout->addWidget(messageLabel, 4,0, 1,2);

	QVBoxLayout* rightLayout = new QVBoxLayout;
	rightLayout->addWidget(findButton);
	rightLayout->addWidget(stopButton);
	rightLayout->addWidget(closeButton);
	rightLayout->addStretch();
	rightLayout->addWidget(helpButton);

	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);

	setWindowTitle(tr("Find Files or Folders"));
}

