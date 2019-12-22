#pragma once

#include "Repo.h"
#include <QAbstractTableModel>

class StarModel : public QAbstractTableModel
{
private:
	Repo& repo;

public:
	StarModel(Repo&repo);
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	int columnCount(const QModelIndex & parent = QModelIndex()) const;

	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole)const;

	void updateAll();




};