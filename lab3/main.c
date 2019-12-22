#include<stdio.h>
#include "controller.h"
#include "map.h"
#include "repo.h"

#include "UI.h"
#include <stdio.h>

int main()
{
	Repo *repo = createRepo();
	Controller *ctrl = createController(repo);

	UI *ui = createUI(ctrl);
	startUI(ui);
	system("pause");
	return 0;
}