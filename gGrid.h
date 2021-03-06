#ifndef __GGRID_H__
#define __GGRID_H__

#include <stdio.h>
#include <stdlib.h>

#include "tools.h"
#include "charray2D.h"

typedef struct _gGrid* gGrid;

struct _gGrid {

	charray data;
	charray skin;
	int sizeCase;
	int size;
	int numberOfSeparators;
	char colorState1;
	char colorState2;
};

gGrid standard_gGrid_create(int size);
gGrid gGrid_create(int size, char colorState1, char colorState2);
void gGrid_skin_init(gGrid grid);
void gGrid_skin_update(gGrid grid);
void gGrid_skin_update_aux(gGrid grid);
void gGrid_destroy(gGrid grid);

int gGrid_are_equal(gGrid grid1, gGrid grid2);
void gGrid_define_sizeCase(gGrid grid);
int gGrid_skin_get_case_lineIndex(gGrid, int lineIndex);
int gGrid_skin_get_case_columnIndex(gGrid grid, int columnIndex);
void gGrid_switch(gGrid grid, int lineIndex, int columnIndex);
void gGrid_inverse_and_warn(gGrid, int lineIndex, int columnIndex);
void gGrid_inverse(gGrid grid, int lineIndex, int columnIndex);
void gGrid_inverse_aux(gGrid grid, int lineIndex, int columnIndex);

#endif
