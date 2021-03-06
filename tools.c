#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "tools.h"

void tools_alloc_init() {
	
	TOOLS_ALLOC = 0;
}

void tools_alloc_check_at_end() {

	if(TOOLS_ALLOC != 0) {

		printf("Il y a une fuite de memoire !\n");
		printf("%d octets de la memoire n'ont pas ete desalloues !\n", TOOLS_ALLOC);
	}
}

void* tools_malloc(int size) {
	
	void* pointer = malloc(size);
	TOOLS_ALLOC += size;	

	return pointer;
}

void tools_free(void* pointer, int size) {

	free(pointer);
	TOOLS_ALLOC -= size;
}

void int_swap(int* value1, int* value2) {

	int tmp = *value1;
	*value1 = *value2;
	*value2 = tmp;

}

void int_normalize_and_warn(int* pointerOfValue, int valueMin, int valueMax) {

	if(*pointerOfValue < valueMin) {
	
		fprintf(stderr, "int_normalize_and_warn : %d change to %d", *pointerOfValue, valueMin);
		*pointerOfValue = valueMin;
	}

	else if(*pointerOfValue > valueMax) {

		fprintf(stderr, "int_normalize_and_warn : %d change to %d", *pointerOfValue, valueMax);
		*pointerOfValue = valueMax;
	}
}

void int_normalize(int* pointerOfValue, int valueMin, int valueMax) {

	if(*pointerOfValue < valueMin)
		*pointerOfValue = valueMin;

	else if(*pointerOfValue > valueMax)
		*pointerOfValue = valueMax;
}

int tools_random_int(int minValue, int maxValue) {
	
	if(minValue > maxValue)
		int_swap(&minValue, &maxValue);

	int amplitude = maxValue - minValue + 1;
	float temporaryValue = (1.0 * rand() / INT_MAX) * amplitude;
	int alea = (int) (minValue + temporaryValue);

	if(alea < minValue)
		alea = minValue;

	else if(alea > maxValue)
		alea = maxValue;

	return alea;
}
