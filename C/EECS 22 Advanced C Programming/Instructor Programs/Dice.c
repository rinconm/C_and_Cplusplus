/* Dice.c: roll the dice			*/
/*						*/
/* author: Rainer Doemer			*/
/*						*/
/* modifications:				*/
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
    int count1 = 0, count2 = 0, count3 = 0,
	count4 = 0, count5 = 0, count6 = 0;

    /* random number generator initialization */
    srand(time(0));

    /* input section */
    printf("Roll the dice: How many times? ");
    scanf("%d", &n);

    /* computation section */
    for(i = 0; i < n; i++)
       { switch(roll())
	    { case 1:
		{ count1++; break; }
	      case 2:
		{ count2++; break; }
	      case 3:
		{ count3++; break; }
	      case 4:
		{ count4++; break; }
	      case 5:
		{ count5++; break; }
	      case 6:
		{ count6++; break; }
	      default:
		{ printf("INVALID ROLL!");
		  exit(10);
		 }
	     } /* hctiws */
        } /* rof */

    /* output section */
    printf("Rolled a 1 %5d times.\n", count1);
    printf("Rolled a 2 %5d times.\n", count2);
    printf("Rolled a 3 %5d times.\n", count3);
    printf("Rolled a 4 %5d times.\n", count4);
    printf("Rolled a 5 %5d times.\n", count5);
    printf("Rolled a 6 %5d times.\n", count6);

    /* exit */
    return 0;
} /* end of main */

/* EOF */
