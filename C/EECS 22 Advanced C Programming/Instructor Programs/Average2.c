/* Average2.c: compute the average of a set of numbers	*/
/*							*/
/* author: Rainer Doemer				*/
/*							*/
/* modifications:					*/
/* 10/10/04 RD	sentinel controlled loop		*/
/* 10/10/04 RD	initial version				*/

#include <stdio.h>

/* main function */

int main(void)
{
   /* variable definitions */
   int    counter;
   double value;
   double total;
   double average;

   /* input and computation section */
   counter = 0;
   total = 0.0;
   while (1)
      { printf("Please enter a value (or -1 to quit): ");
        scanf("%lf", &value);
        if (value == -1.0)
           { break;
            } /* fi */
        total += value;
        counter++;
       } /* elihw */

   /* computation and output section */
   printf("%d values entered.\n", counter);
   if (counter >= 1)
      { average = total / (double)counter;
        printf("The average is %f.\n", average);
       } /* fi */

   /* exit */
   return 0;
} /* end of main */

/* EOF */
