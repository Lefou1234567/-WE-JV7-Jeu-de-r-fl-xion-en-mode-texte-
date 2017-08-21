#ifndef __LGAME_H__
#define __LGAME_H__

#include <stdio.h>
#include <stdlib.h>

#include "tools.h"
#include "charray2D.h"
#include "gGrid.h"

#define DEFAULT_NUMBER_OF_LIFES 3

 /* Difficulty rules : 
  *
  *  -0 : 2 X 2, 1 coup 
  *  -1 : 2 X 2, 2 coups
  *  -2 : 3 X 3, 2 coups
  *  -3 : 4 X 4, 2 coups
  *  -4 : 4 X 4, 3 coups
  */

typedef struct _lgame* lgame;

struct _lgame {

	gGrid example;
	gGrid gridGame;
	int difficulty;
	int gridSize;
	int numberOfTry;
	int numberOfSwitch;
	int remainingSwitch;
	int numberOfLifes;
};

lgame standard_lgame_create(int difficulty);
lgame lgame_create(char colorState1, char colorState2, int difficulty);
lgame lgame_create_aux(int difficulty);
void lgame_destroy(lgame game);
void lgame_inform_player(lgame game);

#endif
