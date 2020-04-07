#include <QSize>
#include "ListModel.h"
#include <QFont>
#include <QBrush>

ListModel::ListModel(QObject* parent /*= Q_NULLPTR*/) :
	QAbstractListModel(parent)
{
	list << 1 << 10 << 20 << 30 << 40;
}

int ListModel::rowCount(const QModelIndex& index) const
{
	return list.count();
}

QVariant ListModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();
	int value = list.at(index.row());
	switch (role) {
	case Qt::DisplayRole:
	case Qt::EditRole:
		return value;
	case Qt::SizeHintRole:
		return QSize(0, 40);
	case Qt::ToolTipRole:
		return QString::number(value);
	case Qt::TextAlignmentRole:
		return Qt::AlignLeft;
	case Qt::FontRole:
		return QFont("Times New Roman", 12, QFont::Bold);
	case Qt::BackgroundRole:
		if (value < 10)
			return QBrush(Qt::red);
		else if (value < 30)
			return QBrush(Qt::yellow);
		else
			return QBrush(Qt::green);
	default:
		return QVariant();
	}
}

bool ListModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (role == Qt::EditRole)
	{
		list.replace(index.row(), value.toInt());
		return true;
	}
	return false;
}

Qt::ItemFlags ListModel::flags(const QModelIndex& index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;
	return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}
