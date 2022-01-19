/* Function.c: compute a math function table	*/
/*						*/
/* author: Rainer Doemer			*/
/*						*/
/* modifications:				*/
/* 10/28/04 RD	initial version			*/

#include <stdio.h>
#include <math.h>

/* function definition */

double f(double x)
{
    return cos(x);
} /* end of f */

/* main function */

int main(void)
{
    /* variable definitions */
    double hi, lo, step;
    double x, y;

    /* input section */
    printf("Please enter the lower bound: ");
    scanf("%lf", &lo);
    printf("Please enter the upper bound: ");
    scanf("%lf", &hi);
    printf("Please enter the step size:   ");
    scanf("%lf", &step);

    /* computation and output section */
    for(x = lo; x <= hi; x += step)
    {
	y = f(x);
	printf("f(%10g) = %10g\n", x, y);
    } /* rof */

    /* exit */
    return 0;
} /* end of main */

/* EOF */
