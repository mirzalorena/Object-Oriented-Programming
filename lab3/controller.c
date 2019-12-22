#include "controller.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Controller *createController(Repo *r) {
	// creating the controller by allocating memory
	Controller *c = (Controller *)malloc(sizeof(Controller));
	// making the repository of the controller the repository we gave
	c->repo = r;
	return c;
}

int addMapCtrl(Controller *c, int addCountryCtrl(Controller *c, int mapNr, int stateDeterior, char* type, int yearStor) {
	// we create a country to add
	Map *m = createMap(nr,state,type,year);
	/*
			In p we got one of this values:
					1-if the adding of of the country succeded
					0-if the adding of the country failed
	*/
	int p = addMap(c->repo, m);
	destroyCountry(co);
	return p;
}