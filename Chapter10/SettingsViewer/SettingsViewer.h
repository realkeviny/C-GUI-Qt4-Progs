#ifndef SETTINGSVIEWER_H
#define SETTINGSVIEWER_H

#include <QDialog>

class QDialogButtonBox;
class QSettings;
class QTreeWidget;
class QTreeWidgetItem;


QT_BEGIN_NAMESPACE
namespace Ui { class SettingsViewerClass; };
QT_END_NAMESPACE

class SettingsViewer : public QDialog
{
    Q_OBJECT

public:
    SettingsViewer(QWidget *parent = nullptr);

private slots:
    void open() override;
private:

    void readSettings();
    void addChildSettings(QSettings& settings, QTreeWidgetItem* item, const QString& group);

    QTreeWidget* treeWidget;
    QDialogButtonBox* buttonBox;

    QString organization;
    QString application;
};

#endif