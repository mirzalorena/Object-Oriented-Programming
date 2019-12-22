#include "WazeObserver.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	Repo repo;
	Controller controller(&repo);

	std::vector<Driver> list = controller.getDrivers();
	for (auto i : list)
	{
		WazeObserver*w = new WazeObserver{ controller,i };
		controller.registerObserver(w);
		std::string print = i.getName() + "->" + i.getStatus() + "<->" + std::to_string(i.getScore());
		w->setWindowTitle(print.c_str());
		if (i.getStatus() == "baby")
			w->setStyleSheet("background-color: magenta");
		else if (i.getStatus() == "regular")
			w->setStyleSheet("background-color: yellow");
		else
			w->setStyleSheet("background-color: blue");
		w->show();

	}
	return a.exec();

}
