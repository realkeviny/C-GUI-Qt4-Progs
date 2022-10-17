#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>

enum
{
	Department_Id = 0,
	Department_Name = 1,
	Department_LocationId = 2
};

class QSqlRelationalTableModel;
class QLabel;
class QTableView;
class QSplitter;
class QPushButton;
class QDialogButtonBox;

class MainForm  : public QWidget
{
	Q_OBJECT

public:
	MainForm();

private slots:
	void updateEmployeeView();
	void addDepartment();
	void deleteDepartment();
	void editEmployees();

private:
	void createDepartmentPanel();
	void createEmployeePanel();

	QSqlRelationalTableModel* departmentModel;
	QSqlRelationalTableModel* employeeModel;
	QWidget* departmentPanel;
	QWidget* employeePanel;
	QLabel* departmentLabel;
	QLabel* employeeLabel;
	QTableView* departmentView;
	QTableView* employeeView;
	QSplitter* splitter;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* editButton;
	QPushButton* quitButton;
	QDialogButtonBox* buttonBox;
};

#endif