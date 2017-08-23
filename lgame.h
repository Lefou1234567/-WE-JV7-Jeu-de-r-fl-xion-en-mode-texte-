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
  *  - 0 : 3 X 2, 1 coup 
  *  - 1 : 3 X 2, 2 coups
  *  - 2 : 4 X 3, 2 coups
  *  - 3 : 5 X 4, 2 coups
  *  - 4 : 5 X 4, 3 coups
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
void lgame_play(lgame game);
void lgame_update_variables(lgame game, int areGridsEqual, int* isGameWon, int* isPlaying);
void lgame_print_result(lgame game, int isGameWon);
void lgame_ask_index_loop(lgame game, int* lineIndex, int* columnIndex);
void lgame_ask_index(lgame game, int* lineIndex, int* columnIndex);
void lgame_set_random_shape(lgame game);
void lgame_shuffle_gridGame(lgame game);

#endif
