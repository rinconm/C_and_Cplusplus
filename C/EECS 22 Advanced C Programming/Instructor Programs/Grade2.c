/* Grade2.c: convert score into letter grade	*/
/*						*/
/* author: Rainer Doemer			*/
/*						*/
/* modifications:				*/
/* 10/18/04 RD	use 'switch' statement		*/
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
   switch (score / 10)
      { case 10:
	case 9:
	   { grade = 'A';
	     break; }
	case 8:
	   { grade = 'B';
	     break; }
	case 7:
	   { grade = 'C';
	     break; }
	case 6:
	   { grade = 'D';
	     break; }
	default:
	   { grade = 'F';
	     break; }
       } /* hctiws */

   /* output section */
   printf("Your letter grade is %c.\n", grade);

   /* exit */
   return 0;
} /* end of main */

/* EOF */
