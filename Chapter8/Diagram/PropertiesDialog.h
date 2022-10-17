#ifndef PROPERITESDIALOG_H
#define PROPERITESDIALOG_H

#include <QtWidgets>

#include "ui_PropertiesDialog.h"

class Node;

class PropertiesDialog : public QDialog,private Ui::PropertiesDialogClass
{
	Q_OBJECT

public:
	PropertiesDialog(Node* node,QWidget *parent = nullptr);


private slots:
	void onbtnBoxaccepted();
	void onBtntextColorClicked();
	void onbtnOutLineColorClicked();
	void onbtnBackGroundColorClicked();

private:
	void updateColorLabel(QLabel* label, const QColor& color);
	void chooseColor(QLabel* label, QColor* color);

	Node* node;
	QColor textColor;
	QColor outlineColor;
	QColor backgroundColor;
};

#endif