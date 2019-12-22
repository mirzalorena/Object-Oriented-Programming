#pragma once
#include "controller.h"

typedef struct {
	Controller *ctrl; // we define the controller for the ui
} UI;

UI *createUI(Controller *c); // we create a ui

void startUI(UI *ui);