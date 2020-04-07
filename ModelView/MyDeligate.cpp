#include "MyDeligate.h"
#include <QSlider>
#include <QApplication>
#include <QStyleOptionProgressBar>

MyDeligate::MyDeligate(QObject* parent/* = Q_NULLPTR*/):
	QStyledItemDelegate(parent)
{

}

QWidget* MyDeligate::createEditor(QWidget* parent, const QStyleOptionViewItem& opton, const QModelIndex& index) const
{
	QSlider* editor = new QSlider(parent);
	editor->setOrientation(Qt::Horizontal);
	editor->setAutoFillBackground(true);
	return editor;
}

void MyDeligate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
	QSlider* slider = qobject_cast<QSlider*>(editor);
	slider->setValue(index.data().toInt());
}

void MyDeligate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
	QSlider* slider = qobject_cast<QSlider*>(editor);
	model->setData(index, slider->value());
}

void MyDeligate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	editor->setGeometry(option.rect);
}


void MyDeligate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	//QStyledItemDelegate::paint(painter, option, index);
	int value = index.data().toInt();
	
	QStyleOptionProgressBar progressbar;
	progressbar.minimum = 0;
	progressbar.maximum = 100;
	progressbar.rect = option.rect;
	progressbar.progress = value;
	progressbar.text = QString::number(value);
	progressbar.textVisible = true;

	QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressbar, painter);
	
}
