#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tools.h"
#include "charray2D.h"
#include "gGrid.h"
#include "lgame.h"


int main(int argc, char** argv) { 

	time_t t;

	tools_alloc_init();

	srand((unsigned) time(&t));
	lgame game = standard_lgame_create(0);
	lgame_play(game);
	lgame_destroy(game);
	tools_alloc_check_at_end();

	return EXIT_SUCCESS;
}
