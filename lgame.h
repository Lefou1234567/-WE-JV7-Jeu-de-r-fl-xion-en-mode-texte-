#ifndef __LGAME_H__
#define __LGAME_H__

#include <stdio.h>
#include <stdlib.h>

#include "tools.h"
#include "charray2D.h"
#include "gGrid.h"

typedef struct _lgame* lgame

struct _lgame {

	gGrid example;
	gGrid gridGame;
	int difficulty;
	int gridSize;
	int numberOfTry;
	int numberOfSwitch;
	int numberOfLifes;

};

#endif
