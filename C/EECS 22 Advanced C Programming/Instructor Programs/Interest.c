/* Interest.c: compound interest on savings account	*/
/*							*/
/* author: Rainer Doemer				*/
/*							*/
/* modifications:					*/
/* 10/18/06 RD	distinguish amount and balance		*/
/* 10/19/04 RD	initial version				*/

#include <stdio.h>

/* main function */

int main(void)
{
   /* variable definitions */
   double amount, balance, rate, interest;
   int    year;

   /* input section */
   printf("Please enter the initial amount in $: ");
   scanf("%lf", &amount);
   printf("Please enter the interest rate in %% : ");
   scanf("%lf", &rate);

   /* computation and output section */
   for(year = 1; year <= 10; year++)
      { interest = amount * (rate/100.0);
	balance = amount + interest;
	printf("Interest for year %2d is $%8.2f,"
		" total balance is $%8.2f.\n",
		year, interest, balance);
	amount = balance;
       } /* rof */

   /* exit */
   return 0;
} /* end of main */

/* EOF */
