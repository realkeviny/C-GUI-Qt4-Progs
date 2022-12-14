#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>

class QCheckBox;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QListWidget;
class QRadioButton;
class QStackedLayout;

class Preferences : public QDialog
{
    Q_OBJECT

public:
    Preferences(QWidget *parent = nullptr);

private:
    void createAppearancePage();
    void createWebBrowserPage();
    void createMailAndNewsPage();
    void createAdvancedPage();

    QStackedLayout* stackedLayout;
    QListWidget* listWidget;
    QWidget* appearancePage;
    QWidget* webBrowserPage;
    QWidget* mailAndNewsPage;
    QWidget* advancedPage;
    QDialogButtonBox* buttonBox;

    QGroupBox* openGroupBox;
    QCheckBox* webBrowserCheckBox;
    QCheckBox* mailEditorCheckBox;
    QCheckBox* newsGroupCheckBox;
    QGroupBox* toolbarsGroupBox;
    QRadioButton* picturesAndTextRadioButton;
    QRadioButton* picturesOnlyRadioButton;
    QRadioButton* textOnlyRadioButton;
    QCheckBox* tooltipsCheckBox;
    QCheckBox* webSiteIconsCheckBox;
    QCheckBox* resizeImagesCheckBox;

    QGroupBox* displayGroupBox;
    QRadioButton* blankRadioButton;
    QRadioButton* homeRadioButton;
    QRadioButton* lastRadioButton;
    QGroupBox* homeGroupBox;
    QLabel* locationLabel;
    QLineEdit* locationLineEdit;
    QGroupBox* webButtonsGroupBox;
    QCheckBox* bookmarksCheckBox;
    QCheckBox* goCheckBox;
    QCheckBox* homeCheckBox;
    QCheckBox* searchCheckBox;
    QCheckBox* printCheckBox;

    QGroupBox* generalGroupBox;
    QCheckBox* confirmCheckBox;
    QCheckBox* rememberCheckBox;
    QGroupBox* mailButtonsGroupBox;
    QCheckBox* fileCheckBox;
    QCheckBox* nextCheckBox;
    QCheckBox* stopCheckBox;
    QCheckBox* junkCheckBox;

    QGroupBox* featuresGroupBox;
    QCheckBox* javaCheckBox;
    QCheckBox* ftpCheckBox;
    QLineEdit* ftpLineEdit;
};

#endif