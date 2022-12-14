#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>
#include <QSet>
#include "ui_FilterDialog.h"

class PumpSpreadsheet;
class PumpFilter;

class FilterDialog : public QDialog,private Ui::FilterDialog
{
	Q_OBJECT

public:
	FilterDialog(QWidget *parent = nullptr);
	
	void initFromSpreadsheet(PumpSpreadsheet* spreadsheet);
	PumpFilter filter() const;
private:
	void populateComboBox(QComboBox* comboBox,
		const QSet<QString>& texts);
	QString comboBoxText(const QComboBox* comboBox) const;
};

#endif