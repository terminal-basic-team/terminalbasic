#ifndef MEMORYMODEL_HPP
#define MEMORYMODEL_HPP

#include <QAbstractTableModel>

class MemoryModel : public QAbstractTableModel
{
	Q_OBJECT
	
public:
	
	explicit MemoryModel(uint8_t*, size_t, QObject* = nullptr);
	    
private:
	
	Q_DISABLE_COPY(MemoryModel)
	
	uint8_t* m_buffer;
	
	size_t m_bufferSize;
	    
public:
	
	int columnCount(const QModelIndex&) const override;
	
	int rowCount(const QModelIndex&) const override;
	
	QVariant headerData(int, Qt::Orientation, int) const override;
	
	QVariant data(const QModelIndex&, int) const override;
	
	bool setData(const QModelIndex&, const QVariant&, int) override;
};

#endif /* MEMORYMODEL_HPP */

