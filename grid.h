#ifndef __GRID_H__
#define __GRID_H__

#include <stdio.h>
#include <stdlib.h>

#include "tools.h"
#include "charray2D.h"

typedef	struct _grid* grid;

struct _grid {

	charray data;
	charray skin;
	int sizeData;
	int skinWidth;
	int skinHeight;
	int sizeCase;
	int nombreSeparator;
	char colorState1;
	char colorState2;
	
};

grid grid_create(int sizeData, char colorState1, char colorState2);
void grid_update_skin(grid grd);
grid standard_grid_create(int size);
void grid_destroy(grid grd);

#endif
