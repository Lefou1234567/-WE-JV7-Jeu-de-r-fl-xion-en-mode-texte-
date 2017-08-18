#include <stdio.h>
#include <stdlib.h>

#include "charray2D.h"
#include "tools.h"

charray charray_create(int width, int height, char background) {

	if(width < 0) {

		width = 0;
		fprintf(stderr, "charray_create : width negative; on la valeur par 0\n");
	}

	if(height < 0) {

		height = 0;
		fprintf(stderr, "charray_create : height negative; on la valeur par 0\n");
	}

	charray tab = tools_malloc(sizeof(struct _charray));
	tab->width = width;
	tab->height = height;
	tab->background = background;

	charray_alloc(tab, tab->width, tab->height);
	charray_fill(tab, background);

	return tab;
}

void charray_alloc(charray tab, int width, int height) {

	if(width < 0) {

		width = 0;
		fprintf(stderr, "charray_alloc : width negative; on la valeur par 0\n");
	}

	if(height < 0) {

		height = 0;
		fprintf(stderr, "charray_alloc : height negative; on la valeur par 0\n");
	}

	tab->data = tools_malloc(sizeof(char) * width * height);
	tab->data2D = tools_malloc(sizeof(char*) * height);

	for(int lineIndex = 0; lineIndex < height; lineIndex++)
		tab->data2D[lineIndex] = tab->data + width * lineIndex * sizeof(char);
	
}

void charray_fill(charray tab, char background) {

	char* pointer = tab->data;

	for(int lineIndex = 0; lineIndex < tab->height; lineIndex++) {

		for(int columnIndex = 0; columnIndex < tab->width; columnIndex++) {

			*pointer = background;
			pointer++;
		}
	}
}

void charray_destroy(charray tab) {

	tools_free(tab->data, sizeof(char) * tab->width * tab->height);
	tools_free(tab->data2D, sizeof(char*) * tab->height);
	tools_free(tab, sizeof(struct _charray));
}

void charray_display(charray tab) {

	char* pointer = tab->data;

	for(int lineIndex = 0; lineIndex < tab->height; lineIndex++) {

		for(int columnIndex = 0; columnIndex < tab->width; columnIndex++) {

			fprintf(stderr, " %c", *pointer);
			pointer++;
		}

		fprintf(stderr, "\n");
	}

}

void charray_set(charray tab, int lineIndex, int columnIndex, char character) {

	tab->data2D[lineIndex][columnIndex] = character;
}

char charray_get(charray tab, int lineIndex, int columnIndex) {

	return tab->data2D[lineIndex][columnIndex];
}

void charray_draw_horizontal_line(charray tab, int columnIndex1, int columnIndex2, int lineIndex, char color) {

	int_normalize(&columnIndex1, 0, tab->width - 1);
	int_normalize(&columnIndex2, 0, tab->width - 1);
	int_normalize(&lineIndex, 0, tab->height - 1);
	
	if(columnIndex1 > columnIndex2)
		int_swap(&columnIndex1, &columnIndex2);

	char* pointer = tab->data + tab->width * lineIndex * sizeof(char) + columnIndex1 * sizeof(char);

	for(int columnIndex = columnIndex1; columnIndex <= columnIndex2; columnIndex++) {

		*pointer = color;
		pointer++;
	}
}

void charray_draw_vertical_line(charray tab, int lineIndex1, int lineIndex2, int columnIndex, char color) {

	int_normalize(&lineIndex1, 0, tab->height - 1);
	int_normalize(&lineIndex2, 0, tab->height - 1);
	int_normalize(&columnIndex, 0, tab->width - 1);

	if(lineIndex1 > lineIndex2)
		int_swap(&lineIndex1, &lineIndex2);

	char* pointer = tab->data + tab->width * lineIndex1 + columnIndex * sizeof(char);

	for(int lineIndex = lineIndex1; lineIndex <= lineIndex2; lineIndex++) {

		*pointer = color;
		pointer += sizeof(char) * tab->width;
	}
}

int charray_are_equal(charray tab1, charray tab2) {

	if(tab1 == tab2)
		return 1;

	if(tab1->width != tab2->width || tab1->height != tab2->height)
		return 0;

	char* pointer1 = tab1->data;
	char* pointer2 = tab2->data;

	for(int lineIndex = 0; lineIndex < tab1->width; lineIndex++) {

		for(int columnIndex = 0; columnIndex < tab1->height; columnIndex++) {
			
			if(*pointer1 != *pointer2)
				return 0;

			pointer1++;
			pointer2++;
		}
	}

	return 1;
}
