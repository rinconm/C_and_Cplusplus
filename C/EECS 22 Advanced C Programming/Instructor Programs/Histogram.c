/* Histogram.c: print a histogram of data values	*/
/*							*/
/* author: Rainer Doemer				*/
/*							*/
/* modifications:					*/
/* 11/02/04 RD	initial version				*/

#include <stdio.h>

/* constants */

#define NUM_ROWS 10

/* main function */

int main(void)
{
   /* variable definitions */
   int Data[NUM_ROWS];
   int i, j, max;
   double scale;

   /* input section */
   for(i = 0; i < NUM_ROWS; i++)
      { printf("Please enter data value %2d: ", i+1);
	scanf("%d", &Data[i]);
       } /* rof */

   /* computation section */
   max = 0;
   for(i = 0; i < NUM_ROWS; i++)
      { if (Data[i] > max)
	   { max = Data[i];
	    } /* fi */
       } /* rof */
   scale = 70.0 / max;

   /* output section */
   for(i = 0; i < NUM_ROWS; i++)
      { printf("%2d: %5d ", i+1, Data[i]);
	for(j = 0; j < Data[i]*scale; j++)
	   { printf("*");
	    } /* rof */
	printf("\n");
       } /* rof */

   /* exit */
   return 0;
} /* end of main */

/* EOF */
