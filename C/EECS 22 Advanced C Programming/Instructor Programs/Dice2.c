/* Dice2.c: roll the dice			*/
/*						*/
/* author: Rainer Doemer			*/
/*						*/
/* modifications:				*/
/* 11/04/04 RD	version using arrays		*/
/* 10/28/04 RD	initial version			*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function definition */

int roll(void)
{
    int r;

    r = rand() % 6 + 1;
 /* printf("Rolled a %d.\n", r); */
    return r;
} /* end of roll */

/* main function */

int main(void)
{
    /* variable definitions */
    int i, n;
    int count[6] = { 0, 0, 0, 0, 0, 0 };

    /* random number generator initialization */
    srand(time(0));

    /* input section */
    printf("Roll the dice: How many times? ");
    scanf("%d", &n);

    /* computation section */
    for(i = 0; i < n; i++)
       { count[roll()-1]++;
        } /* rof */

    /* output section */
    for(i = 0; i < 6; i++)
       { printf("Rolled a %d %5d times.\n", i+1, count[i]);
	} /* rof */

    /* exit */
    return 0;
} /* end of main */

/* EOF */
