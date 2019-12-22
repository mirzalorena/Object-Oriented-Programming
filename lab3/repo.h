#pragma once
#include "array.h"
#include "map.h"

typedef struct {
	Arrays *maps; // we define our dynamic arrays
} Repo;

Repo *createRepo();                        // we create a repo
int findPosOfMaps(Repo *v, char *name); // returns a position of a country if
										   // found, otherwise returns -1
int addMap(Repo *v, Map *m);    // adding a country to a repository
int deleteMap(Repo *v, int nrMap); // deleting a country from a repository
int updateMap(Repo *v, int *stateDeter, char *type, int *yearStor);



