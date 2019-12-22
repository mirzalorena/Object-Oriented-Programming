#include "Lab11.h"
//#include <QtWidgets/QApplication>
//#include <qpushbutton.h>
#include <QLabel>
#include "Evidence.h"
#include "EvidenceValidator.h"
#include "Exception.h"
#include "Repository.h"
#include "MemoryRepository.h"
#include "FileRepository.h"
#include "Controller.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel.h>
#include <qpushbutton.h>
#include <qboxlayout.h>
#include <qmessagebox.h>
#include "ui_myList.h"
#include "GUI.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	std::string option = readOption("choice.txt");
	if (option == "file repository")
	{
		FileRepository fileRepository("evidence.txt");
		MemoryRepository userRepository{};

		EvidenceValidator validator{};
		Controller controller{ &fileRepository,&userRepository,validator };
		Lab11 gui{ controller };


		gui.show();

		return a.exec();
	}
	else if (option == "memory repository")
	{
		MemoryRepository adminRepository{};
		MemoryRepository userRepository{};

		EvidenceValidator validator{};
		Controller controller{ &adminRepository,&userRepository,validator };
		Lab11 gui{ controller };

		gui.show();

		return a.exec();
	}
	else
	{
		std::cout << "Invalid access mode\n";
	}


	return a.exec();

	


}
