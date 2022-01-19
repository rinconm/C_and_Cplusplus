/* Addition.c: adding two integer numbers	*/
/*						*/
/* author: Rainer Doemer			*/
/*						*/
/* modifications:				*/
/* 09/30/04 RD	initial version			*/

#include <stdio.h>

/* main function */

int main(void)
{
    /* variable definitions */
    int	i1 = 0;	/* first integer */
    int	i2 = 0;	/* second integer */
    int	sum;	/* result */

    /* input section */
    printf("Please enter an integer:      ");
    scanf("%d", &i1);
    printf("Please enter another integer: ");
    scanf("%d", &i2);

    /* computation section */
    sum = i1 + i2;

    /* output section */
    printf("The sum of %d and %d is %d.\n", i1, i2, sum);

    /* exit */
    return 0;
} /* end of main */

/* EOF */
