#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

UI *createUI(Controller *c) {
	UI *ui = (UI *)malloc(sizeof(UI)); // allocating space for the ui
	ui->ctrl = c; // making the controller of the controller the controller we
				  // gave
	return ui;
}

void print_menu()
{
	printf("1.Add a NEW MAP \n");
	printf("2.Update something about a map \n");
	printf("3.Delete a map \n");
	printf("4.See ALL maps \n");
	printf("5.See all the maps of a type at your choosing \n");
	printf("0.Exit \n");
	printf("\n");
}

int getCmd() {
	int cmd = getInteger("Give command: ");
	if (cmd >= 0 && cmd <= 10)
		return cmd;
	return -1;
}

int add_new_map(UI *ui)
{
	int map_nr = 0, state_deterior = 0, year_stor = 0;
	char map_type[20];
	printf("NEW MAP! \n");
	printf("Map Catalogue Number: ");
	scanf("%d", map_nr);
	printf("State of deterioration: ");
	scanf("%d", state_deterior);
	printf("Map Type: ");
	scanf("%s", map_type);
	printf("Year of storage: ");
	scanf("%d", year_stor);
	return addCountryCtrl(ui->ctrl, map_nr, state_deterior, year_stor, map_type);
}

void start_UI(UI *ui)
{
	// we do this loop until the command is 0
	while (1) {
		printMenu();
		// we read the command
		int cmd = getCmd();
		// we read the command until is a valid one
		while (cmd == -1) {
			printf("Please input a valid command!\n");
			cmd = getCmd();
		}
		// we exit the while loop
		if (cmd == 0)
			break;
		switch (cmd) {
			// we go through all of the menu option
			// and also verify if it can be done
		case 1: {
			int res = addCountryUI(ui);
			if (res == 1)
				printf("Country successfully added.\n");
			else
				printf("Error! Countryt could not be added, as there is another "
					"country with the same name or invalid continent!\n");
			break;
		}
		}
}