/* Fibonacci.c: example demonstrating recursion	*/
/*						*/
/* author: Rainer Doemer			*/
/*						*/
/* modifications:				*/
/* 11/14/04 RD	initial version			*/

#include <stdio.h>

/* function definition */

long fibonacci(long n)
{
   if (n <= 1)	/* base case */
      { return n;
       } /* fi */
   else		/* recursion step */
      { return fibonacci(n-1) + fibonacci(n-2);
       } /* esle */
} /* end of fibonacci */

/* main function */

int main(void)
{
   /* variable definitions */
   long int n, f;

   /* input section */
   printf("Please enter value n: ");
   scanf("%ld", &n);

   /* computation section */
   f = fibonacci(n);

   /* output section */
   printf("The %ld-th Fibonacci number is %ld.\n", n, f);

   /* exit */
   return 0;
} /* end of main */

/* EOF */
