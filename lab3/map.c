#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "map.h"

Map* createMap(int mapNr, int stateDeterior, char* type, int yearStor)
{
	map->mapNr = mapNr;
	map->stateDeterior = stateDeterior;
	strcpy(p->type, type);
	map->yearStor = yearStor;

	return map;
}

int getMapNr(Map* map) {
	return map->mapNr;
}

int getStateDeterior(Map* map) {
	return map->stateDeterior;
}

char* getType(Map* map) {
	return map->type;
}

int getYearStor(Map* map) {
	return map->yearStor;
}