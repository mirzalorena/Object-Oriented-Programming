#pragma once 
typedef struct {
	int mapNr;
	int stateDeterior;
	char* type;
	int yearStor;
} Map;

Map* createMap(int mapNr, int stateDeterior, char* type, int yearStor);

//getters and setters
int getMapNr(Map* map);
int getStateDeterior(Map* map);
char* getType(Map* map);
int getYearStor(Map* map);
