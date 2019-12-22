#include "StarCatalogueMVC.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	Repo repo;
	Controller controller( &repo );
	StarModel * model = new StarModel{ repo };

	auto list = controller.getAstronomers();
	
		for (auto i : list)
		{
			StarCatalogueMVC* w = new StarCatalogueMVC{ controller,model,i };
			w->show();
		}
		return a.exec();
}




