#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>

#include "ui_SortDialog.h"

class SortDialog : public QDialog,public Ui::SortDialog
{
	Q_OBJECT

public:
	SortDialog(QWidget* parent = nullptr);

	void SetColumnRange(QChar First, QChar Last);
};

#endif
