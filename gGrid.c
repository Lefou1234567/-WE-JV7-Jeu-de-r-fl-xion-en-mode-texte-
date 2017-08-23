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
	char* pointer = grid->skin->data;
	
	for(int lineIndex = 0; lineIndex < grid->skin->height; lineIndex++) {

		for(int columnIndex = 0; columnIndex < grid->skin->width; columnIndex++) {
			
			*pointer = grid->data->data2D[gGrid_skin_get_case_lineIndex(grid, lineIndex)][gGrid_skin_get_case_columnIndex(grid, columnIndex)];
			pointer++;
		}
	}

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

int gGrid_are_equal(gGrid grid1, gGrid grid2) {

	if(grid1 == grid2)
		return 1;

	else if(charray_are_equal(grid1->data, grid2->data))
		return 1;

	return 0;
}

int gGrid_skin_get_case_lineIndex(gGrid grid, int lineIndex) {
	
	int_normalize(&lineIndex, 0, grid->skin->height);
	
	for(int lineIndexData = 0; lineIndexData < grid->data->width; lineIndexData++) {

		if(lineIndexData * (grid->sizeCase + 1) <= lineIndex && lineIndex <= lineIndexData * (grid->sizeCase + 1) + grid->sizeCase  - 1)
			return lineIndexData;	
	}	

	return 0;
}

int gGrid_skin_get_case_columnIndex(gGrid grid, int columnIndex) {

	int_normalize(&columnIndex, 0, grid->skin->width);

	for(int columnIndexData = 0; columnIndexData < grid->data->width; columnIndexData++) {

		if(columnIndexData * (grid->sizeCase + 1) <= columnIndex && columnIndex <= columnIndexData * (grid->sizeCase + 1) + grid->sizeCase - 1)
			return columnIndexData;
	}

	return 0;
}

void gGrid_inverse_and_warn(gGrid grid, int lineIndex, int columnIndex) {

	if(lineIndex < 0 || lineIndex >= grid->size) {

		fprintf(stderr, "Les coordonees saisis sont invalides !\n");
		return;
	}
	
	else if(columnIndex < 0 || columnIndex >= grid->size) {
		
		fprintf(stderr, "Les coordonnees saisis sont invalides !\n");
		return;
	}

	gGrid_inverse_aux(grid, lineIndex, columnIndex);
}

void gGrid_inverse(gGrid grid, int lineIndex, int columnIndex) {

	if(lineIndex < 0 || lineIndex >= grid->size)
		return;

	else if(columnIndex < 0 || columnIndex >= grid->size)
		return;

	gGrid_inverse_aux(grid, lineIndex, columnIndex);
}

void gGrid_inverse_aux(gGrid grid, int lineIndex, int columnIndex) {

	if(grid->data->data2D[lineIndex][columnIndex] == grid->colorState1)
		grid->data->data2D[lineIndex][columnIndex] = grid->colorState2;
	
	else
		grid->data->data2D[lineIndex][columnIndex] = grid->colorState1;

	gGrid_skin_update(grid);
}

void gGrid_switch(gGrid grid, int lineIndex, int columnIndex) {

	if(lineIndex < 0 || lineIndex >= grid->size) {

		fprintf(stderr, "Les coordonees saisies sont invalides !\n");
		return;
	}

	if(columnIndex < 0 || columnIndex >= grid->size) {

		fprintf(stderr, "Les coordonees saisies sont invaldies !\n");
		return;
	}

	for(int lineIndex2 = lineIndex - 1; lineIndex2 < lineIndex + 2; lineIndex2++) {

		for(int columnIndex2 = columnIndex - 1; columnIndex2 < columnIndex + 2; columnIndex2++)
			gGrid_inverse(grid, lineIndex2, columnIndex2);
	}
}

