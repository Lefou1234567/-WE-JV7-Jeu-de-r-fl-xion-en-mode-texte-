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

	gGrid example;
	fprintf(stderr, "\n\nNombre de coups restant : %d\n", game->remainingSwitch); fprintf(stderr, "Vie restante : %d\n", game->numberOfLifes - game->numberOfTry); 
} 

void lgame_play(lgame game) { 

	int isPlaying = 1;
	int isGameWon = 0;
	int lineIndex;
	int columnIndex;

	lgame_set_random_shape(game);
	lgame_shuffle_gridGame(game);

	while(isPlaying) {

		game->remainingSwitch = game->numberOfSwitch;
		while(game->remainingSwitch != 0) {
		
			lgame_inform_player(game);
			lgame_ask_index_loop(game, &lineIndex, &columnIndex);
			gGrid_switch(game->gridGame, lineIndex, columnIndex);
			game->remainingSwitch--;
		}
		
		lgame_update_variables(game, gGrid_are_equal(game->example, game->gridGame), &isGameWon, &isPlaying);
	}

	lgame_print_result(game, isGameWon);
}

void lgame_update_variables(lgame game, int areGridsEqual, int* isGameWon, int* isPlaying) {

	if(areGridsEqual) {

		*isGameWon = 1;
		*isPlaying = 0;
	}
	
	else
		game->numberOfLifes--;

	if(game->numberOfLifes <= 0) {
		
		*isPlaying = 0;
		*isGameWon = 0;
	}
}

void lgame_ask_index_loop(lgame game, int* lineIndex, int* columnIndex) {

	int areWrongIndex = 0;
	
	do {

		lgame_ask_index(game, lineIndex, columnIndex);
	
		if((*lineIndex < 0 || *lineIndex >= game->gridGame->size) || (*columnIndex < 0 || *columnIndex >= game->gridGame->size)) {
		
			areWrongIndex = 1;
			fprintf(stderr, "\nLes donnees entrees ne sont pas correctes, veuillez recommencer !\n\n");
		}
		
		else 
			areWrongIndex = 0;
	
	} while(areWrongIndex);
	
}

void lgame_print_result(lgame game, int isGameWon) {

	lgame_inform_player(game);

	fprintf(stderr, "\n");
	if(isGameWon) 
		fprintf(stderr, "Vous avez gagne !!!\n");
	else 
		fprintf(stderr, "Vous avez perdu...\n");

}

void lgame_ask_index(lgame game, int* lineIndex, int* columnIndex) {

	int error;

	printf("Selectionnez une colone (1-%d) : \n> ", game->gridGame->size);
	error = scanf("%d", columnIndex);
	fprintf(stderr, "\n");
	printf("Selectionnez une ligne (1-%d) : \n> ", game->gridGame->size);
	error = scanf("%d", lineIndex);

	(*lineIndex)--;
	(*columnIndex)--;
}

void lgame_set_random_shape(lgame game) {

	int lineIndex;
	int columnIndex;

	for(int i = 0; i < 100; i++) {
	
		lineIndex = tools_random_int(0, game->example->size - 1);
		columnIndex = tools_random_int(0, game->example->size - 1);

		gGrid_switch(game->example, lineIndex, columnIndex);
		gGrid_switch(game->gridGame, lineIndex, columnIndex);
	}
	
	
}

void lgame_shuffle_gridGame(lgame game) {
  
	int lineIndex;
	int columnIndex;

	for(int numberOfSwitch = 0; numberOfSwitch < game->remainingSwitch; numberOfSwitch++) {
	
		lineIndex = tools_random_int(0, game->gridGame->size - 1);
		columnIndex = tools_random_int(0, game->gridGame->size - 1);

		gGrid_switch(game->gridGame, lineIndex, columnIndex);
	}
}

