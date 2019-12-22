#include "ExamOOP.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	Repo repo;
	Controller controller{ &repo };

	//controller.tests();

	std::vector<Ethnologist> users = repo.getEth();

	for (auto u : users)
	{
		ExamOOP * w = new ExamOOP{ controller,u };
		controller.registerObserver(w);
		std::string print = u.getName() + "->" + u.getThematicSector();
		w->setWindowTitle(print.c_str());
		w->show();
	}
	return a.exec();
}
