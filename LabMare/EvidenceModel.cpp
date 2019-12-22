#include "EvidenceModel.h"
#include <qcolor.h>

EvidenceModel::EvidenceModel(Repository & repository):repository(repository)
{
}

int EvidenceModel::rowCount(const QModelIndex & parent) const
{
	return this->repository.getEvidence().size();
}

int EvidenceModel::columnCount(const QModelIndex & parent) const
{
	return 5;
}

QVariant EvidenceModel::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	int col = index.column();

	Evidence currentEvidence = this->repository.getEvidence()[row];

	if (role == Qt::DisplayRole)
	{
		switch (col)
		{
		case 0:
			return QString::fromStdString(currentEvidence.getId());
		case 1:
			return QString::fromStdString(currentEvidence.getMeasurement());
		case 2:
			return QString::fromStdString(std::to_string(currentEvidence.getimageClarityLevel()));
		case 3:
			return QString::fromStdString(std::to_string(currentEvidence.getQuantity()));
		case 4:
			return QString::fromStdString(currentEvidence.getPhotograph());
		default:
			break;
		}
	}
	if (role == Qt::BackgroundColorRole)
	{
		if (row % 2 == 0)
			return QColor{ Qt::magenta };
	}

	return QVariant();
}

QVariant EvidenceModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
	{
		switch (section)
		{
		case 0:
			return "ID";
		case 1:
			return "Measurement";
		case 2:
			return "Image clarity level";
		case 3:
			return "Quantity";
		case 4:
			return "Photograph";
		}
	}

	return QVariant();
}

bool EvidenceModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (role == Qt::EditRole || role == Qt::DisplayRole)
	{
		Evidence& currentEvidence = this->repository.getEvidence()[index.row()];
		int column = index.column();
		switch (column)
		{
		case 0:
		{currentEvidence.setId(value.toString().toStdString());
		break; }
		case 1:
		{currentEvidence.setMeasurement(value.toString().toStdString());
		break; }
		case 2:
		{currentEvidence.setImageClarityLevel(atof(value.toString().toStdString().c_str()));
		break; }
		case 3:
		{currentEvidence.setQuantity(atof(value.toString().toStdString().c_str()));
		break; }
		case 4:
		{currentEvidence.setPhotograph(value.toString().toStdString());
		break; }
		}
	}
	//emit dataChanged(index, index);
	return true;
}

Qt::ItemFlags EvidenceModel::flags(const QModelIndex & index) const
{
	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}
