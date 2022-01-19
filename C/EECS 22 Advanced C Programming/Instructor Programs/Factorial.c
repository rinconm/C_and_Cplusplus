/* Factorial.c: example demonstrating recursion	*/
/*						*/
/* author: Rainer Doemer			*/
/*						*/
/* modifications:				*/
/* 11/14/04 RD	initial version			*/

#include <stdio.h>

/* function definition */

long factorial(long n)
{
   if (n == 1)	/* base case */
      { return 1;
       } /* fi */
   else		/* recursion step */
      { return n * factorial(n-1);
       } /* esle */
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
