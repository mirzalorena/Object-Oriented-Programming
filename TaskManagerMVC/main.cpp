#include "TaskManagerMVC.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	Repo repo;
	Controller controller(&repo);
	TaskModel *model = new TaskModel{ repo };

	auto list = repo.getProgrammers();
	for (auto i : list)
	{
		TaskManagerMVC* w = new TaskManagerMVC{ controller,model,i };
		w->show();
	}
	return a.exec();


}
