#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QDialog>

class QComboBox;
class QDataWidgetMapper;
class QDateEdit;
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QSqlRelationalTableModel;

enum
{
	Employee_Id = 0,
	Employee_Name = 1,
	Employee_DepartmentId = 2,
	Employee_Extension = 3,
	Employee_Email = 4,
	Employee_StartDate = 5,
};

class EmployeeForm : public QDialog
{
    Q_OBJECT

public:
	EmployeeForm(int id, QWidget* parent = nullptr);

	void done(int result);

private slots:
	void addEmployee();
	void deleteEmployee();

private:
	QSqlRelationalTableModel* tableModel;
	QDataWidgetMapper* mapper;
	QLabel* nameLabel;
	QLabel* departmentLabel;
	QLabel* extensionLabel;
	QLabel* emailLabel;
	QLabel* startDateLabel;
	QLineEdit* nameEdit;
	QComboBox* departmentComboBox;
	QLineEdit* extensionLineEdit;
	QLineEdit* emailEdit;
	QDateEdit* startDateEdit;
	QPushButton* firstButton;
	QPushButton* previousButton;
	QPushButton* nextButton;
	QPushButton* lastButton;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* closeButton;
	QDialogButtonBox* buttonBox;
};

#endif