#ifndef __CHARRAY2D_H__
#define __CHARRAY2D_H__

#include <stdio.h>
#include <stdlib.h>

#include "tools.h"

typedef struct _charray* charray;

struct _charray {
	
	int width;
	int height;
	char background;
	char* data;
	char** data2D;
};

 /* Primitives generales */
charray charray_create(int width, int height, char background);
void charray_alloc(charray tab, int width, int height);
void charray_fill(charray tab, char background);
void charray_destroy(charray tab);
void charray_display(charray tab);
void charray_set(charray tab, int lineIndex, int columnIndex, char character);
char charray_get(charray tab, int lineIndex, int columnIndex);

 /* ------------------------------------------------------- */

void charray_draw_horizontal_line(charray tab, int columnIndex1, int columnIndex2, int lineIndex, char color);
void charray_draw_vertical_line(charray tab, int lineIndex1, int lineIndex2, int columnIndex, char color);
int charray_are_equal(charray tab1, charray tab2);

#endif
