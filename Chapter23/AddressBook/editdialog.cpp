#include "editdialog.h"
#include "abitem.h"
#include <QtWidgets>

EditDialog::EditDialog(QTreeWidget* treeWidget, QWidget* parent /* = 0 */) :QDialog(parent)
{
	setupUi(this);

	this->treeWidget = treeWidget;
	currentItem = 0;

	setWindowTitle(tr("Add Entry"));
}

EditDialog::EditDialog(ABItem* item, QWidget* parent /* = 0 */) :QDialog(parent)
{
	setupUi(this);

	contactLineEdit->setText(item->contact());
	addressLineEdit->setText(item->address());
	phoneNumberLineEdit->setText(item->phoneNumber());
	treeWidget = item->treeWidget();
	currentItem = item;
}

void EditDialog::accept()
{
	if (!currentItem)
	{
		currentItem = new ABItem(treeWidget);
	}
	currentItem->setContact(contactLineEdit->text());
	currentItem->setAddress(addressLineEdit->text());
	currentItem->setPhoneNumber(phoneNumberLineEdit->text());

	QDialog::accept();
}