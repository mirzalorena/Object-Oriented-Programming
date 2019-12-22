#include "TaskModel.h"

#include "qcolor.h"

TaskModel::TaskModel(Repo& repo) :repo(repo) {}

int TaskModel::rowCount(const QModelIndex & parent) const
{
	return repo.getNrofTasks();
}

int TaskModel::columnCount(const QModelIndex & parent) const
{
	return 4;
}

QVariant TaskModel::data(const QModelIndex &index, int role)const
{
	int i = index.row();
	int j = index.column();

	Task task = repo.getTaskByIndex(i);

	if (role == Qt::DisplayRole)
	{
		if (j == 0)
			return QString::fromStdString(task.getDescription());
		else if (j == 1)
			return QString::fromStdString(task.getStatus());
		else if (j == 2)
		{
			int id = task.getId();
			if (id == -1)
				return "Nu e nimeni pe drum";
			else {
				return id;
			}

		}
		else if (j == 3)
			return QString::fromStdString(repo.getProgrNameById(task.getId()));
		
	}
	else if (role == Qt::BackgroundColorRole)
	{
		if (task.getStatus() == "open")
			return QColor(Qt::red);
		else if (task.getStatus() == "in progress")
			return QColor(Qt::yellow);
		else {
			return QColor(Qt::magenta);
		}
	}
	return QVariant();
}

QVariant TaskModel::headerData(int section, Qt::Orientation orientation, int role)const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
	{
		switch (section)
		{
		case 0:return "Description";
		case 1:return "Status";
		case 2: return "Programmer ID";
		case 3: return "Programmer Name";
		default:break;
		}
	}
	return QVariant();
}

void TaskModel::updateAll()
{
	emit layoutChanged();
}