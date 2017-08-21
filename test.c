#include <stdio.h>
#include <stdlib.h>

#include "tools.h"
#include "charray2D.h"
#include "gGrid.h"


int main(int argc, char** argv) { 

	tools_alloc_init();

	gGrid grid = gGrid_create(5, '~', '#');

	charray_display(grid->skin);
	fprintf(stderr, "\n\n");
	
	gGrid_destroy(grid);
	tools_alloc_check_at_end();

	return EXIT_SUCCESS;
}
