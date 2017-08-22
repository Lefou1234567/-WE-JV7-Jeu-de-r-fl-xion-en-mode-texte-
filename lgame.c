#include <stdio.h>
#include <stdlib.h>

#include "lgame.h"
#include "tools.h"
#include "charray2D.h"
#include "gGrid.h"

lgame standard_lgame_create(int difficulty) {

	lgame game = lgame_create_aux(difficulty);	
	game->example = standard_gGrid_create(game->gridSize);
	game->gridGame = standard_gGrid_create(game->gridSize);

	return game;
}

lgame lgame_create(char colorState1, char colorState2, int difficulty) {
	
	lgame game = lgame_create_aux(difficulty);
	game->example = gGrid_create(game->gridSize, colorState1, colorState2);
	game->gridGame = gGrid_create(game->gridSize, colorState1, colorState2);

	return game;
}

lgame lgame_create_aux(int difficulty) {
	 
	lgame game = tools_malloc(sizeof(struct _lgame));
	game->numberOfLifes = DEFAULT_NUMBER_OF_LIFES;
	game->numberOfTry = 0;
	game->difficulty = difficulty;

	switch (game->difficulty) {

	case 0 :
		game->gridSize = 3;
		game->numberOfSwitch = 1;
		break;

	case 1 : 
		game->gridSize = 3;
		game->numberOfSwitch = 2;
		break;
	
	case 2 : 
		game->gridSize = 4;
		game->numberOfSwitch = 2;
		break;

	case 3 :
		game->gridSize = 5;
		game->numberOfSwitch = 2;
		break;

	case 4 : 
		game->gridSize = 5;
		game->numberOfSwitch = 3;
		break;
	
	default : 
		game->gridSize = 3;
		game->numberOfSwitch = 2;
		break;
	}

	game->remainingSwitch = game->numberOfSwitch;

	return game;
}

void lgame_destroy(lgame game) {

	gGrid_destroy(game->example);
	gGrid_destroy(game->gridGame);
	tools_free(game, sizeof(struct _lgame));
}

void lgame_inform_player(lgame game) {

	fprintf(stderr, "But :\n\n");
	charray_display(game->example->skin);
	fprintf(stderr, "\nGrille actuelle :\n\n");
	charray_display(game->gridGame->skin);

	fprintf(stderr, "\n\nNombre de coups restant : %d\n", game->remainingSwitch);
	fprintf(stderr, "Vie restante : %d\n", game->numberOfLifes - game->numberOfTry);

}
