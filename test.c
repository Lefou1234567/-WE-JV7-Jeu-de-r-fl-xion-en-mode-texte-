#include <stdio.h>
#include <stdlib.h>

#include "tools.h"
#include "charray2D.h"
#include "grid.h"

int main(int argc, char** argv) {

	tools_alloc_init();

	grid grd = standard_grid_create(3);

	grid_destroy(grd);

	tools_alloc_check_at_end();
	return EXIT_SUCCESS;
}
