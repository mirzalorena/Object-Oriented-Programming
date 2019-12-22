#include "StarModel.h"

#include "qcolor.h"

StarModel::StarModel(Repo&repo) :repo(repo) {}

int StarModel::rowCount(const QModelIndex & parent)const
{
	return repo.getNrOfStars();
}

int StarModel::columnCount(const QModelIndex & parent)const
{
	return 5;
}

QVariant StarModel::data(const QModelIndex &index, int role)const
{
	int i = index.row();
	int j = index.column();

	Star star = repo.getStarByIndex(i);

	if (role == Qt::DisplayRole)
	{
		if (j == 0)
			return QString::fromStdString(star.getName());
		else if (j == 1)
			return QString::fromStdString(star.getConst());
		else if (j == 2)
		{
			int ra = star.getCoords().getRa();
			if (ra == -1)
				return "None";
			else { return ra; }
		}
		else if (j == 3)
		{
			int dec = star.getCoords().getDec();
			if (dec == -1)
				return "None";
			else { return dec; }
		}
		else if (j == 4)
		{
			int d = star.getDiameter();
			if (d == -1)
				return "none";
			else { return d; }
		}
	}
	else if (role == Qt::BackgroundColorRole)
	{
		if (star.getConst() == "caru")
			return QColor(Qt::magenta);
		else {
			return QColor(Qt::yellow);
		}
	}
	return QVariant();

}

QVariant StarModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
	{
		switch (section)
		{
		case 0:return "Name";
		case 1: return "Constellation";
		case 2: return "Right Ascension";
		case 3: return "Declination";
		case 4: return "Diameter";
		default:break;
		}
	
	}
	return QVariant();
}

void StarModel::updateAll()
{
	emit layoutChanged();
}