#include "memorymodel.hpp"

MemoryModel::MemoryModel(uint8_t* buf, size_t len, QObject* parent) :
    QAbstractTableModel(parent),
    m_buffer(buf),
    m_bufferSize(len)
{
}

int
MemoryModel::columnCount(const QModelIndex& parent) const
{
	return 8;
}

int
MemoryModel::rowCount(const QModelIndex& parent) const
{
	return m_bufferSize % 8 ? m_bufferSize / 8 + 1 : m_bufferSize / 8;
}

QVariant
MemoryModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();
	
	if (role != Qt::DisplayRole)
		return QVariant();
	
	size_t ind = index.row() * 8 + index.column();
	auto res = QString::number(m_buffer[ind], 16);
	if (res.length() < 2)
		res = '0' + res;
	
	return QVariant(res);
}

bool
MemoryModel::setData(const QModelIndex& index, const QVariant& data, int role)
{
	return false;
}

QVariant
MemoryModel::headerData(int sec, Qt::Orientation o, int role) const
{
	if (role != Qt::DisplayRole)
		return QVariant();
	
	if (o == Qt::Horizontal)
		return sec;
	else if (o == Qt::Vertical)
		return QString::number(sec * 8, 16);
}
