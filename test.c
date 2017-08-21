#include <stdio.h>
#include <stdlib.h>

#include "tools.h"
#include "charray2D.h"
#include "gGrid.h"
#include "lgame.h"


int main(int argc, char** argv) { 

	tools_alloc_init();

	lgame game = standard_lgame_create(0);
	
	fprintf(stderr, "\n");
	lgame_inform_player(game);
	fprintf(stderr, "\n\n");
	lgame_destroy(game);
	tools_alloc_check_at_end();

	return EXIT_SUCCESS;
}
