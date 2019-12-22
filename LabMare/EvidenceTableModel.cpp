#include "EvidenceTableModel.h"
#include <QFont>
#include <qbrush.h>

EvidenceTableModel::EvidenceTableModel(Repository & repo, QObject * parent):QAbstractTableModel{parent},repo{repo}
{
}

EvidenceTableModel::~EvidenceTableModel()
{
}

int EvidenceTableModel::rowCount(const QModelIndex & parent) const
{
	int evidenceNumber = this->repo.getEvidence().size();
	return evidenceNumber + 1;
}

int EvidenceTableModel::columnCount(const QModelIndex & parent) const
{
	return 5;
}

QVariant EvidenceTableModel::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	int column = index.column();

	std::vector<std::string> command;
	command.push_back("mylist");

	std::vector<Evidence> evidence = this->repo.getEvidence();

	if (row == evidence.size())
	{
		return QVariant();
	}
	Evidence evid = evidence[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(evid.getId());
		case 1:
			return QString::fromStdString(evid.getMeasurement());
		case 2:
			return QString::number(evid.getimageClarityLevel());
		case 3:
			return QString::number(evid.getQuantity());
		case 4:
			return QString::fromStdString(evid.getPhotograph());
		default:
			break;
		}
	}

	if (role == Qt::FontRole)
	{
		QFont font("Times", 15, 10, true);
		font.setItalic(false);
		return font;
	}
	if (role == Qt::BackgroundRole)
	{
		if (row % 2 == 1)
		{
			return QBrush{ QColor{0,250,154} };
		}
	}
	return QVariant{};
}

QVariant EvidenceTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		switch (section)
		{
		case 0:
			return QString{ "ID" };
		case 1:
			return QString{ "Measurement" };
		case 2:
			return QString{ "Image clarity level" };
		case 3:
			return QString{ "Quantity" };
		case 4:
			return QString{ "Photograph" };
		default:
			break;
		}
	}
	if (role == Qt::FontRole)
	{
		QFont font("Times", 15, 10, true);
		font.setBold(true);
		font.setItalic(false);
		return font;
	}

	return QVariant();
}

bool EvidenceTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;

	int evidenceIndex = index.row();

	std::vector<Evidence> evidence = this->repo.getEvidence();

	if (evidenceIndex == evidence.size())
	{
		this->beginInsertRows(QModelIndex{}, evidenceIndex, evidenceIndex);

		switch (index.column())
		{
		//case 0:
			//this->repo.addEvidence(Evidence{ value.toString().toStdString(),"","",0,0 ,"" });

			default:
				break;
		}
		this->endInsertRows();
		return true;
	}
	Evidence& currentEvidence = evidence[evidenceIndex];
	switch (index.column())
	{
	case 0:
		currentEvidence.setId(value.toString().toStdString());
		break;
	case 1:
		currentEvidence.setMeasurement(value.toString().toStdString());
		break;
	case 2:
		currentEvidence.setImageClarityLevel(value.toFloat());
		break;
	case 3:
		currentEvidence.setQuantity(value.toFloat());
	case 4:
		currentEvidence.setPhotograph(value.toString().toStdString());


	}
	this->repo.updateEvidence(evidence[evidenceIndex].getId(), currentEvidence);
	emit dataChanged(index, index);
	return true;
}

Qt::ItemFlags EvidenceTableModel::flags(const QModelIndex & index) const
{
	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}
