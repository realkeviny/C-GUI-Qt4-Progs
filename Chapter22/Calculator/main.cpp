#include "Calculator.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Calculator calc;
	QDir::setCurrent(app.applicationDirPath());
	calc.show();
	return app.exec();
}
