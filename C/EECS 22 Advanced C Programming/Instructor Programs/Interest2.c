/* Interest2.c: compound interest on savings account	*/
/*							*/
/* author: Rainer Doemer				*/
/*							*/
/* modifications:					*/
/* 10/23/05 RD	version to demonstrate debugging	*/
/* 10/19/04 RD	initial version				*/

#include <stdio.h>

/* main function */

int main(void)
{
   /* variable definitions */
   double amount, balance, rate, interest;
   int    year;

   /* input section */
   printf("Please enter the initial amount in $:\n");
   scanf("%lf", &amount);
   printf("Please enter the interest rate in %%:\n");
   scanf("%lf", &rate);

   /* computation and output section */
   for(year = 1; year <= 10; year++)
      { interest = amount * (rate/100.0);
	balance = amount + interest;
	printf("Interest for year%3d is $%8.2f.\n", year, interest);
	printf("The new balance is      $%8.2f.\n", balance);
	amount = balance;
       } /* rof */

   /* exit */
   return 0;
} /* end of main */

/* EOF */
