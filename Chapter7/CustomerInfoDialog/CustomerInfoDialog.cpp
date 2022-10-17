#include "CustomerInfoDialog.h"

#include <QtWidgets>

CustomerInfoDialog::CustomerInfoDialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    ui.firstNameEdit->installEventFilter(this);
    ui.lastNameEdit->installEventFilter(this);
    ui.cityEdit->installEventFilter(this);
    ui.phoneNumberEdit->installEventFilter(this);
}

CustomerInfoDialog::~CustomerInfoDialog()
{
	
}

bool CustomerInfoDialog::eventFilter(QObject* watched, QEvent* event)
{
	if(watched == ui.firstNameEdit || watched == ui.lastNameEdit || watched == ui.cityEdit || watched == ui.phoneNumberEdit)
	{
		if(event->type() == QEvent::KeyPress)
		{
			QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
			if(keyEvent->key()==Qt::Key_Space)
			{
				focusNextChild();
				return true;
			}
		}
	}
	return QDialog::eventFilter(watched, event);
}

