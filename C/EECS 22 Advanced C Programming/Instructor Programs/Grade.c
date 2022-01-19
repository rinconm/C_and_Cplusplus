/* Grade.c: convert score into letter grade	*/
/*						*/
/* author: Rainer Doemer			*/
/*						*/
/* modifications:				*/
/* 10/17/04 RD	initial version			*/

#include <stdio.h>

/* main function */

int main(void)
{
   /* variable definitions */
   int  score = 0;
   char grade;

   /* input section */
   while (score < 1 || score > 100)
      { printf("Please enter your score (1-100): ");
        scanf("%d", &score);
       } /* elihw */

   /* computation section */
   if (score >= 90)
      { grade = 'A'; }
   else
      { if (score >= 80)
           { grade = 'B'; }
        else
           { if (score >= 70)
	        { grade = 'C'; }
	     else
		{ if (score >= 60)
		     { grade = 'D'; }
		  else
		     { grade = 'F'; }
		} /* esle */
	   } /* esle */
      } /* esle */

   /* output section */
   printf("Your letter grade is %c.\n", grade);

   /* exit */
   return 0;
} /* end of main */

/* EOF */
