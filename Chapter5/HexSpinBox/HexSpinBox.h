#ifndef HEXSPINBOX_H
#define HEXSPINBOX_H


#include <QSpinBox>

class QRegExpValidator;

class HexSpinBox : public QSpinBox
{
    Q_OBJECT

public:
    HexSpinBox(QWidget *parent = nullptr);
    //~HexSpinBox();

protected:
    QValidator::State validate(QString& input, int& pos) const override;
    int valueFromText(const QString& text) const override;
    QString textFromValue(int val) const override;

private:
    QRegExpValidator* validator;
};

#endif