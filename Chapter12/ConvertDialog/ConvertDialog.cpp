#include "ConvertDialog.h"
#include <QtWidgets>
#include <QDir>

ConvertDialog::ConvertDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

    QPushButton* convertButton = buttonBox->button(QDialogButtonBox::Ok);
    convertButton->setText("&Convert");
    convertButton->setEnabled(false);

    connect(browseButton, SIGNAL(clicked()), this, SLOT(onbtnBrowseClicked()));
    connect(convertButton, SIGNAL(clicked()), this, SLOT(convertImage()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    connect(&process, SIGNAL(readyReadStandardError()), this, SLOT(updateOutputTextEdit()));
    connect(&process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(processFinished(int, QProcess::ExitStatus)));
    connect(&process, SIGNAL(error(QProcess::ProcessError)), this, SLOT(processError(QProcess::ProcessError)));
}

void ConvertDialog::onbtnBrowseClicked()
{
    QString initialName = sourceFilEdit->text();
    if(initialName.isEmpty())
    {
        initialName = QDir::homePath();
    }
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose File"), initialName);

    fileName = QDir::toNativeSeparators(fileName);
    if(!fileName.isEmpty())
    {
        sourceFilEdit->setText(fileName);
        buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

void ConvertDialog::convertImage()
{
    QString sourceFile = sourceFilEdit->text();
    targetFile = QFileInfo(sourceFile).path() + QDir::separator() + QFileInfo(sourceFile).baseName() + "." + targetFormatComboBox->currentText().toLower();
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    outputTextEdit->clear();

    QStringList args;
    if(enhanceCheckBox->isChecked())
    {
        args << "-enhance";
    }
    if(monochromeCheckBox->isChecked())
    {
        args << "-monochrome";
    }
    args << sourceFile << targetFile;

    process.start("convert", args);
}

void ConvertDialog::updateOutputTextEdit()
{
    QByteArray newData = process.readAllStandardError();
    QString text = outputTextEdit->toPlainText() + QString::fromLocal8Bit(newData);
    outputTextEdit->setPlainText(text);
}

void ConvertDialog::processFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
	if(exitStatus==QProcess::CrashExit)
	{
        outputTextEdit->append(tr("Conversion program crashed"));
	}
    else if(exitCode!=0)
    {
        outputTextEdit->append(tr("Conversion failed"));
    }
	else
	{
        outputTextEdit->append(tr("File %1 created").arg(targetFile));
	}
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}

void ConvertDialog::processError(QProcess::ProcessError error)
{
	if(error==QProcess::FailedToStart)
	{
        outputTextEdit->append(tr("Conversion program not found"));
        buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
	}
}

