#include "TaskManagerObserver.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	Repo repo;
	Controller controller{ &repo };

	std::vector<Programmer> list = controller.getProgrammers();
	for (auto i : list)
	{
		TaskManagerObserver* w = new TaskManagerObserver{ controller,i };
		controller.registerObserver(w);
		w->setWindowTitle(i.getName().c_str());
		w->show();
	}
	return a.exec();

}
