#include "Bronze.h"
#include <QtWidgets>

void Bronze::polish(QPalette& palette)
{
	QPixmap backgroundImage(":/image/images/background.png");
	QColor bronze(207, 155, 95);
	QColor veryLightBlue(239, 239, 247);
	QColor lightBlue(223, 223, 239);
	QColor darkBlue(95, 95, 191);

	palette = QPalette(bronze);
	palette.setBrush(QPalette::Window, backgroundImage);
	palette.setBrush(QPalette::BrightText, Qt::white);
	palette.setBrush(QPalette::Base, veryLightBlue);
	palette.setBrush(QPalette::AlternateBase, lightBlue);
	palette.setBrush(QPalette::Highlight, darkBlue);
	palette.setBrush(QPalette::Disabled, QPalette::Highlight, Qt::darkGray);
}

void Bronze::polish(QWidget* widget)
{
	if (qobject_cast<QAbstractButton*> (widget) || qobject_cast<QAbstractSpinBox*>(widget))
	{
		widget->setAttribute(Qt::WA_Hover, true);
	}
}

void Bronze::unpolish(QWidget* widget)
{
	if (qobject_cast<QAbstractButton*> (widget) || qobject_cast<QAbstractSpinBox*>(widget))
	{
		widget->setAttribute(Qt::WA_Hover, false);
	}
}

int Bronze::styleHint(StyleHint which, const QStyleOption* option, const QWidget* widget /* = nullptr */, QStyleHintReturn* returnData /* = nullptr */) const
{
	switch (which)
	{
	case SH_DialogButtonLayout:
	{
		return static_cast<int>(QDialogButtonBox::MacLayout);
		break;
	}
	case SH_EtchDisabledText:
	{
		return static_cast<int>(true);
	}
	case SH_DialogButtonBox_ButtonsHaveIcons:
	{
		return static_cast<int>(true);
	}
	case SH_UnderlineShortcut:
	{
		return static_cast<int>(false);
	}
	default:
		return QCommonStyle::styleHint(which, option, widget, returnData);
	}
}

int Bronze::pixelMetric(PixelMetric which, const QStyleOption* option, const QWidget* widget /* = nullptr */) const
{
	switch (which)
	{
	case QStyle::PM_ButtonDefaultIndicator:
		return 0;
	case PM_IndicatorWidth:
	case PM_IndicatorHeight:
		return 16;
	case PM_CheckBoxLabelSpacing:
		return 8;
	case PM_DefaultFrameWidth:
		return 2;
	default:
		return QCommonStyle::pixelMetric(which, option, widget);
	}
}

QIcon Bronze::standardIcon(StandardPixmap which, const QStyleOption* option, const QWidget* widget /* = nullptr */) const
{
	QImage image = QCommonStyle::standardPixmap(which, option, widget).toImage();
	if (image.isNull())
	{
		return QIcon();
	}
	QPalette palette;
	if (option)
	{
		palette = option->palette;
	}
	else if (widget)
	{
		palette = widget->palette();
	}

	QPainter painter(&image);
	painter.setOpacity(0.25);
	painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
	painter.fillRect(image.rect(), palette.highlight());

	painter.end();

	return QIcon(QPixmap::fromImage(image));
}

void Bronze::drawPrimitive(PrimitiveElement which, const QStyleOption* option, QPainter* painter, const QWidget* widget) const 
{
	switch (which)
	{
	case PE_IndicatorCheckBox:
		drawBronzeCheckBoxIndicator(option, painter);
		break;
	case PE_PanelButtonCommand:
		drawBronzeBevel(option, painter);
		break;
	case PE_Frame:
		drawBronzeFrame(option, painter);
		break;
	case PE_FrameDefaultButton:
		break;
	default:
		QCommonStyle::drawPrimitive(which, option, painter, widget);
	}
}

void Bronze::drawComplexControl(ComplexControl which, const QStyleOptionComplex* option, QPainter* painter, const QWidget* widget) const
{
	if (which == CC_SpinBox)
	{
		drawBronzeSpinBoxButton(SC_SpinBoxDown, option, painter);
		drawBronzeSpinBoxButton(SC_SpinBoxUp, option, painter);
		QRect rect = subControlRect(CC_SpinBox, option,
			SC_SpinBoxEditField)
			.adjusted(-1, 0, +1, 0);
		painter->setPen(QPen(option->palette.mid(), 1.0));
		painter->drawLine(rect.topLeft(), rect.bottomLeft());
		painter->drawLine(rect.topRight(), rect.bottomRight());
	}
	else
	{
		return QCommonStyle::drawComplexControl(which, option, painter, widget);
	}
}

QRect Bronze::subControlRect(ComplexControl whichControl, const QStyleOptionComplex* option, SubControl whichSubControl, const QWidget* widget) const 
{
	if (whichControl == CC_SpinBox)
	{
		int frameWidth = pixelMetric(PM_DefaultFrameWidth, option, widget);
		int buttonWidth = 16;

		switch (whichSubControl)
		{
		case SC_SpinBoxFrame:
			return option->rect;
		case SC_SpinBoxEditField:
			return option->rect.adjusted(+buttonWidth, +frameWidth, -buttonWidth, -frameWidth);
		case SC_SpinBoxDown:
			return visualRect(option->direction, option->rect, QRect(option->rect.x(), option->rect.y(), buttonWidth, option->rect.height()));
		case SC_SpinBoxUp:
			return visualRect(option->direction, option->rect, QRect(option->rect.right() - buttonWidth, option->rect.y(), buttonWidth, option->rect.height()));
		default:
			return QRect();
		}
	}
}

void Bronze::drawBronzeFrame(const QStyleOption* option, QPainter* painter) const
{
	painter->save();
	painter->setRenderHint(QPainter::Antialiasing, true);
	painter->setPen(QPen(option->palette.windowText(), 1.0));
	painter->drawRect(option->rect.adjusted(+1, +1, -1, -1));
	painter->restore();
}

void Bronze::drawBronzeBevel(const QStyleOption* option, QPainter* painter) const
{
	QColor buttonColor = option->palette.button().color();
	int coeff = (option->state & State_MouseOver) ? 115 : 105;

	QLinearGradient gradient(0, 0, 0, option->rect.height());
	gradient.setColorAt(0.0, option->palette.light().color());
	gradient.setColorAt(0.2, buttonColor.lighter(coeff));
	gradient.setColorAt(0.8, buttonColor.darker(coeff));
	gradient.setColorAt(1.0, option->palette.dark().color());

	double penWidth = 1.0;
	if (const QStyleOptionButton* buttonOpt = qstyleoption_cast<const QStyleOptionButton*>(option))
	{
		if (buttonOpt->features & QStyleOptionButton::DefaultButton)
		{
			penWidth = 2.0;
		}
	}

	QRect roundRect = option->rect.adjusted(+1, +1, -1, -1);
	if (!roundRect.isValid())
	{
		return;
	}

	int diameter = 12;
	int cx = 100 * diameter / roundRect.width();
	int cy = 100 * diameter / roundRect.height();

	painter->save();
	painter->setPen(Qt::NoPen);
	painter->setBrush(gradient);
	painter->drawRoundedRect(roundRect, cx, cy);

	if (option->state & (State_On | State_Sunken))
	{
		QColor slightlyOpaqueBlack(0, 0, 0, 63);
		painter->setBrush(slightlyOpaqueBlack);
		painter->drawRoundedRect(roundRect, cx, cy);
	}

	painter->setRenderHint(QPainter::Antialiasing, true);
	painter->setPen(QPen(option->palette.windowText(), penWidth));
	painter->setBrush(Qt::NoBrush);
	painter->drawRoundedRect(roundRect, cx, cy);
	painter->restore();
}

void Bronze::drawBronzeSpinBoxButton(SubControl which, const QStyleOptionComplex* option, QPainter* painter) const
{
	PrimitiveElement arrow = PE_IndicatorArrowLeft;
	QRect buttonRect = option->rect;
	if ((which == SC_SpinBoxUp) != (option->direction == Qt::RightToLeft))
	{
		arrow = PE_IndicatorArrowRight;
		buttonRect.translate(buttonRect.width() / 2, 0);
	}
	buttonRect.setWidth((buttonRect.width() + 1) / 2);

	QStyleOption buttonOpt(*option);

	painter->save();
	painter->setClipRect(buttonRect, Qt::IntersectClip);
	if (!(option->activeSubControls & which))
	{
		buttonOpt.state &= ~(State_MouseOver | State_On | State_Sunken);
	}
	drawBronzeBevel(&buttonOpt, painter);

	QStyleOption arrowOpt(buttonOpt);
	arrowOpt.rect = subControlRect(CC_SpinBox, option, which).adjusted(+3, +3, -3, -3);
	if (arrowOpt.rect.isValid())
	{
		drawPrimitive(arrow, &arrowOpt, painter);
	}
	painter->restore();
}

void Bronze::drawBronzeCheckBoxIndicator(const QStyleOption* option, QPainter* painter) const
{
	painter->save();
	painter->setRenderHint(QPainter::Antialiasing, true);

	if (option->state & State_MouseOver)
	{
		painter->setBrush(option->palette.alternateBase());
	}
	else
	{
		painter->setBrush(option->palette.base());
	}
	painter->drawRoundedRect(option->rect.adjusted(+1, +1, -1, -1), 0, 0);

	if (option->state & (State_On | State_NoChange))
	{
		QPixmap pixmap;
		if (!option->state & State_Enabled)
		{
			pixmap.load(":/image/images/checkmark-disabled.png");
		}
		else if (option->state & State_NoChange)
		{
			pixmap.load(":/image/images/checkmark-partial.png");
		}
		else
		{
			pixmap.load(":/image/images/checkmark.png");
		}

		QRect pixmapRect = pixmap.rect().translated(option->rect.topLeft()).translated(+2, -6);
		QRect painterRect = visualRect(option->direction, option->rect, pixmapRect);

		if (option->direction == Qt::RightToLeft)
		{
			painter->scale(-1.0, +1.0);
			painterRect.moveLeft(-painterRect.right() - 1);
		}
		painter->drawPixmap(painterRect, pixmap);
	}
	painter->restore();
}