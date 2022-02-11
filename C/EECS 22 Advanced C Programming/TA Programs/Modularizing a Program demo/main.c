#include "Aging.h"
#include "Global.h"
#include "SL.h"

#include <stdio.h>
#include <string.h>


int main() {
	unsigned char   R[WIDTH][HEIGHT];	/* use three 2-D arrays to store R, G, B components */
	unsigned char   G[WIDTH][HEIGHT];
	unsigned char   B[WIDTH][HEIGHT];
	int choice;
	int rc;
	char fname[SLEN];

	printf("\n----------------------------\n");
	printf(" 1: Load a PPM image\n");
	printf(" 2: Save a PPM image\n");
	printf(" 3: Age the image\n");
	printf(" 4: Exit\n");

	printf("Please make your choice: ");
	scanf("%d", &choice);
	while (choice != 4) {
		if (choice == 1) {
			printf("Please input the file name to load: ");
			scanf("%75s", fname);
			rc = LoadImage(fname, R, G, B);
		}
		/* menu item 2 - 3 requires image is loaded first */
		else if (choice >=2 && choice<=3) {
			if (rc != 0)	 {
				printf("No image is read.\n");
			}
			/* now image is loaded */
			else {
				switch(choice) {
					case 2:
						printf("Please input the file name to save: ");
						scanf("%75s", fname);
						SaveImage(fname, R, G, B);
						break;
					case 3:
						Aging(R,G,B);
						printf("Aging operation done!");
						break;
					default:
						break;
				}
			}
		}
		else {
			printf("Invalid selection!\n");
		}

		/* Process finished, waiting for another input */
		printf("\n----------------------------\n");
		printf(" 1: Load a PPM image\n");
		printf(" 2: Save a PPM image\n");
		printf(" 3: Age the image\n");
		printf(" 4: Exit\n");

		printf("Please make your choice: ");
		scanf("%d", &choice);
	}
	printf("You exit the program.\n");
	return 0;
}
