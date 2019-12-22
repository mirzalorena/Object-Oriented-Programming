#include "repo.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Repo *createRepo() {
	Repo *v =(Repo *)malloc(sizeof(Repo)); // allocating the space for the repository
	v->maps = createArrays(2); // creating the dynamic array for the repository
	return v;
}

int addMap(Repo *v, Map *m) {
	if (v == NULL)
		return 0;
	// a copy of the Country which was passed will be stored, such that the memory
	// for the Country can be deallocated where it was allocated (in Controller)
	// and the Repository will handle its own memory
	Map *copy = copyMap(m);
	addToArray(v->maps, copy);

	return 1;
}

