#include <stdio.h>
#include <stdlib.h> 
#include "tools.h"
#include "charray2D.h"
#include "gGrid.h"

/*
	charray data;
	charray skin;
	int sizeCase;
	int size;
	int numberOfSeparators;
	char colorState1;
	char colorState2;
*/

gGrid standard_gGrid_create(int size) {

	return gGrid_create(size, '~', '#');
}

gGrid gGrid_create(int size, char colorState1, char colorState2) {
	
	gGrid grid = tools_malloc(sizeof(struct _gGrid));
	grid->data = charray_create(size, size, colorState1);
	grid->size = size;
	grid->sizeCase = 15 / size;
	grid->numberOfSeparators = size - 1;	
	grid->colorState1 = colorState1;
	grid->colorState2 = colorState2; 
	gGrid_skin_init(grid);
	

	return grid;
}

void gGrid_skin_init(gGrid grid) {

	gGrid_skin_update_aux(grid);
}

void gGrid_skin_update(gGrid grid) {
	
	charray_destroy(grid->skin);
	gGrid_skin_update_aux(grid);
}

void gGrid_skin_update_aux(gGrid grid) {
	
	grid->skin = charray_create(grid->size * grid->sizeCase + grid->numberOfSeparators, grid->size * grid->sizeCase + grid->numberOfSeparators, grid->colorState1);
	
	int curseur = 0;

	for(int i = 1; i <= grid->numberOfSeparators; i++) {
	
		curseur += grid->sizeCase;
		charray_draw_vertical_line(grid->skin, 0, grid->skin->height - 1, curseur, ' ');
		curseur++;
	}
	
	curseur = 0;
	
	for(int i = 1; i <= grid->numberOfSeparators; i++) {

		curseur += grid->sizeCase;
		charray_draw_horizontal_line(grid->skin, 0, grid->skin->width - 1, curseur, ' ');
		curseur++;
	}
}

void gGrid_destroy(gGrid grid) {

	charray_destroy(grid->skin);
	charray_destroy(grid->data);
	tools_free(grid, sizeof(struct _gGrid));
}

int gGrid_skin_get_case_lineIndex(gGrid grid, int lineIndex) {
	
	int_normalize(&lineIndex, 0, grid->skin->height);
	
	for(int lineIndexData = 0; lineIndexData < grid->data->width; lineIndexData++) {

		if(lineIndexData * grid->sizeCase + lineIndexData <= lineIndex && lineIndex >= (lineIndexData + 1) * grid->sizeCase + lineIndexData + 1)
			return lineIndexData;

	}	

	fprintf(stderr, "gGrid_skin_get_case_lineIndex : Index non trouve !\n");

	return 0;
}

