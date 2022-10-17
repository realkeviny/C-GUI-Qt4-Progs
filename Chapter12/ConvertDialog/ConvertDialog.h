#ifndef CONVERTDIALOG_H
#define CONVERTDIALOG_H

#include <QDialog>
#include <QProcess>
#include "ui_ConvertDialog.h"

class ConvertDialog : public QDialog,private Ui::ConvertDialogClass
{
    Q_OBJECT

public:
    ConvertDialog(QWidget *parent = nullptr);

private slots:
    void onbtnBrowseClicked();
    void convertImage();
    void updateOutputTextEdit();
    void processFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void processError(QProcess::ProcessError error);

private:
    QProcess process;
    QString targetFile;
};

#endif