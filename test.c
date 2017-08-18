#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	
	int cote = 3;
	int nombreCaseX = 2;
	int nombreCaseY = 1;

	for(int y = 0; y < cote * nombreCaseY; y++) {
	
		for(int x = 0; x < cote * nombreCaseX; x++) {

			if((x + 1) / cote < 1)
				printf("# ");
			
			else if ((x + 1) / cote == 1) {

				if((x + 1) % cote == 0)
					printf("# ");
				else
					printf("~ ");
			}
			
			else
				printf("~ ");
		}
		
		printf("\n");
	}

	printf("\n\n");

	return EXIT_SUCCESS;
}