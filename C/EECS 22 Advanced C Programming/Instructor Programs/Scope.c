/* Scope.c: example demonstrating scope rules	*/
/*						*/
/* author: Rainer Doemer			*/
/*						*/
/* modifications:				*/
/* 10/30/04 RD	initial version			*/

#include <stdio.h>

int square(int a);	/* global function declarations */
int add_y(int x);

int x = 5,		/* global variables */
    y = 7;

int square(int a)	/* global function definition */
{
   int s;		/* local variable */

   s = a * a;
   return s;
}

int add_y(int x)	/* global function definition */
{
   int s;		/* local variable */

   s = x + y;
   return s;
}

int main(void)		/* main function definition */
{
   int z;		/* local variable */

   z = square(x);
   z = add_y(z);

   printf("%d, %d, %d\n", x, y, z);
   return 0;
}

/* EOF */
