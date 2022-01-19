/* Factorial2.c: example demonstrating iteration	*/
/*							*/
/* author: Rainer Doemer				*/
/*							*/
/* modifications:					*/
/* 11/14/04 RD	initial version (based on Factorial.c)	*/

#include <stdio.h>

/* function definition */

long factorial(long n)
{
   long product, factor;

   product = n;
   for(factor = n-1; factor >=1; factor--)
      { product *= factor;
       } /* rof */
   return product;
} /* end of factorial */

/* main function */

int main(void)
{
   /* variable definitions */
   long int n, f;

   /* input section */
   printf("Please enter value n: ");
   scanf("%ld", &n);

   /* computation section */
   f = factorial(n);

   /* output section */
   printf("The factorial of %ld is %ld.\n", n, f);

   /* exit */
   return 0;
} /* end of main */

/* EOF */
