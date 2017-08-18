#include <stdio.h>
#include <stdlib.h>

#include "grid.h"
#include "tools.h"
#include "charray2D.h"

/*
	charray data;
	charray skin;
	int sizeData;
	int sizeCase;
	int nombreSeparator;
	char colorState1;
	char colorState2;
 */


grid grid_create(int sizeData, char colorState1, char colorState2) {
	
	grid newGrid = tools_malloc(sizeof(struct _grid));
	newGrid->data = charray_create(sizeData, sizeData, colorState1);
	newGrid->colorState1 = colorState1;
	newGrid->colorState2 = colorState2;
	newGrid->sizeData = sizeData;
	grid_update_skin(newGrid);
}

void grid_update_skin(grid grd) {

	int lineIndex = 0;
	int columnIndex = 0;

	grd->sizeCase = 15 / grd->sizeData;
	grd->nombreSeparator = grd->sizeData - 1;
	grd->skin = charray_create(grd->sizeData * grd->sizeCase + grd->nombreSeparator * 2, grd->sizeData * grd->sizeCase + grd->nombreSeparator, grd->colorState1);


	//Dessiner les separateurs horizontaux
	for(int i = 0; i < grd->nombreSeparator; i++) {

		lineIndex += grd->sizeCase + 1;
		charray_draw_horizontal_line(grd->skin, 0, grd->skin->width - 1, lineIndex, ' ');
		lineIndex ++;
		charray_draw_horizontal_line(grd->skin, 0, grd->skin->width - 1, lineIndex, ' ');
	}


	//Dessiner les separateurs verticaux
	for(int i = 0; i < grd->nombreSeparator; i++) {

		columnIndex += grd->sizeCase + 1;
		charray_draw_vertical_line(grd->skin, 0, grd->skin->height - 1, columnIndex, ' ');
	}
}

grid standard_grid_create(int size) {

	return grid_create(size, '~', '#');
}

void grid_destroy(grid grd) {

	printf("skin\n\n");
	charray_destroy(grd->skin);
	printf("data\n\n");
	charray_destroy(grd->data);
	printf("grid\n\n");
	tools_free(grd, sizeof(struct _grid));
}
