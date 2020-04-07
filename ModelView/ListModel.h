#pragma once

#include <QAbstractListModel>
#include <QAbstractItemModel>

class ListModel :public QAbstractListModel {
	Q_OBJECT

public:
	explicit ListModel(QObject* parent = Q_NULLPTR);

	int rowCount(const QModelIndex& index = QModelIndex()) const override;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

	Qt::ItemFlags flags(const QModelIndex& index) const override;
private:
	QList<int> list;
};