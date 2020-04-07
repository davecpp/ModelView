#pragma once
#include <QStyledItemDelegate>


class MyDeligate :public QStyledItemDelegate
{
	Q_OBJECT
public:
	explicit MyDeligate(QObject* parent = Q_NULLPTR);
	//create editor widget
	QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& opton, const QModelIndex& index) const override;

	//transfer value from model to editor
	void setEditorData(QWidget* editor, const QModelIndex& index) const override;

	//transfer value from editor to model
	void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const override;

	//set editor geometry
	void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

	//paint element
	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

};

