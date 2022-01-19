/* Square.c: example demonstrating functions	 */
/*						 */
/* author: Rainer Doemer			 */
/*						 */
/* modifications:				 */
/* 10/27/08 RD	renamed parameters and arguments */
/* 10/27/04 RD	initial version			 */

#include <stdio.h>

/* function declaration */

double square(double p);

/* function definition */

double square(double p)
{   double r;
    r = p * p;
    return r;
} /* end of square */

/* main function */

int main(void)
{
    /* variable definitions */
    double a, b;

    /* input section */
    printf("Please enter a value for the argument: ");
    scanf("%lf", &a);

    /* computation section */
    b = square(a);

    /* output section */
    printf("The square of %g is %g\n", a, b);

    /* exit */
    return 0;
} /* end of main */

/* EOF */
