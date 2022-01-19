/* Example Input:
Input: n
output: n=3

*****
 ***
  *

*/

#include <stdio.h>

int main(void)
{
   char num;           // User input
   int i, j;	       // for loop variables
   int starcount;      // Number of stars per line

   // Prompt for input and convert to decimal value
   printf("Please enter a number from 0 to 9: ");
   scanf(" %c", &num);
   num -= 48;
   
   // Star creation per line depending on input value
   starcount = num * 2 - 1;
   for (i=1; i<=num; i++) {
      if (i>1){
        for (j=1; j<=i-1; j++)
           printf(" ");
      }
      for(j=1; j<=starcount; j++)
         printf("*");
   printf("\n");
   starcount -= 2;
   }
}