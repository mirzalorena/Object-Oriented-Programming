#include "QuestionsAndAnswersObserver.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	Repo repo;
	Controller controller{ &repo };

	std::vector<User> list = controller.getUsers();

	for (auto i : list)
	{
		QuestionsAndAnswersObserver*w = new QuestionsAndAnswersObserver{ controller,i };
		controller.registerObserver(w);
		w->setWindowTitle(i.getName().c_str());
		w->show();
	}
	return a.exec();


}
