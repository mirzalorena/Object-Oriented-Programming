#pragma once
#include "repo.h"

typedef struct {
	Repo *repo; // we create a repository into the controller
} Controller;

Controller *createController(Repo *r);

// all of these 3 function retuns 1 if the succeded an 0 if they failed
int addCountryCtrl(Controller *c, int *mapNr, int *stateDeterior, char* type, int *yearStor); // we add a country to the repo

