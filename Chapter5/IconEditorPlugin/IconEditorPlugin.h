#include <QtDesigner/QDesignerCustomWidgetInterface>



class IconEditorPlugin : public QObject,public QDesignerCustomWidgetInterface
{
    Q_OBJECT
	Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    IconEditorPlugin(QObject *parent = nullptr);

    QString name() const override;
    QString includeFile() const override;
    QString group() const override;
    QIcon icon() const override;
    QString toolTip() const override;
    QString whatsThis() const override;
    bool isContainer() const override;
    QWidget* createWidget(QWidget* parent) override;

private:
};
