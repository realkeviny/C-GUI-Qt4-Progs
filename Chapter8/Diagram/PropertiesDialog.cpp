#include "PropertiesDialog.h"
#include "Node.h"

PropertiesDialog::PropertiesDialog(Node* node,QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	this->node = node;
	XSpinBox->setValue(static_cast<int>(node->x()));
	YSpinBox->setValue(static_cast<int>(node->y()));
	textColor = node->textColor();
	outlineColor = node->outlineColor();
	backgroundColor = node->backgroundColor();

	updateColorLabel(outlineColorLabel, outlineColor);
	updateColorLabel(backgroundColorLabel, backgroundColor);
	updateColorLabel(textColorLabel, textColor);
}


void PropertiesDialog::onbtnBoxaccepted()
{
	node->setPos(XSpinBox->value(), YSpinBox->value());
	node->setText(textLineEdit->text());
	node->setOutlineColor(outlineColor);
	node->setBackgroundColor(backgroundColor);
	node->setTextColor(textColor);
	node->update();
	QDialog::accept();
}

void PropertiesDialog::onBtntextColorClicked()
{
	chooseColor(textColorLabel, &textColor);

}

void PropertiesDialog::onbtnOutLineColorClicked()
{
	chooseColor(outlineColorLabel, &outlineColor);
}

void PropertiesDialog::onbtnBackGroundColorClicked()
{
	chooseColor(backgroundColorLabel, &backgroundColor);
}

void PropertiesDialog::updateColorLabel(QLabel* label, const QColor& color)
{
	QPixmap pixmap(16, 16);
	pixmap.fill(color);
	label->setPixmap(pixmap);
}

void PropertiesDialog::chooseColor(QLabel* label, QColor* color)
{
	QColor newColor = QColorDialog::getColor(*color, this);
	if(newColor.isValid())
	{
		*color = newColor;
		updateColorLabel(label, *color);
	}
}