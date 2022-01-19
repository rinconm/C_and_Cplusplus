/* BubbleSort2.c: sort strings alphabetically	*/
/*						*/
/* author: Rainer Doemer			*/
/*						*/
/* modifications:				*/
/* 09/02/13 RD	pointer table for efficiency	*/
/* 11/01/06 RD	swap only adjacent elements	*/
/* 11/06/04 RD	initial version			*/

#include <stdio.h>
#include <string.h>

/* constant definitions */

#define NUM 10	/* ten strings  */
#define LEN 20	/* of length 20 */

/* function declarations */

void EnterText(char Text[NUM][LEN], char *P[NUM]);
void PrintText(char *P[NUM]);
void SwapStrings(char *P[NUM], int i, int j);
void BubbleSort(char *P[NUM]);

/* function definitions */

/* let the user enter the text array		*/

void EnterText(char Text[NUM][LEN], char *P[NUM])
{
   int i;

   for(i = 0; i < NUM; i++)
      { printf("Enter text string %2d: ", i+1);
	scanf("%19s", Text[i]);
	P[i] = Text[i];
       } /* rof */
} /* end of EnterText */

/* print the text array on the screen		*/

void PrintText(char *P[NUM])
{
   int i;

   for(i = 0; i < NUM; i++)
      { printf("String %2d: %s\n", i+1, P[i]);
       } /* rof */
} /* end of PrintText */

/* swap/exchange the pointers to two strings	*/

void SwapStrings(char *P[NUM], int i, int j)
{
    char *tmp;

    tmp = P[i];
    P[i] = P[j];
    P[j] = tmp;
} /* end of SwapStrings */

/* sort the text array by comparing every pair	*/
/* of strings; if the pair of strings is not in	*/
/* alphabetical order, swap it			*/

void BubbleSort(char *P[NUM])
{
   int p, i;

   for(p = 1; p < NUM; p++)
      { for(i = 0; i < NUM-1; i++)
	   { if (strcmp(P[i], P[i+1]) > 0)
		{ SwapStrings(P, i, i+1);
		 } /* fi */
	    } /* rof */
       } /* rof */
} /* end of BubbleSort */

/* main function: enter, sort, print the text	*/

int main(void)
{
   /* local variables */
   char Text[NUM][LEN]; /* NUM strings, length LEN */
   char *P[NUM];	/* NUM pointers to strings */

   /* input section */
   EnterText(Text, P);

   /* computation section */
   BubbleSort(P);

   /* output section */
   PrintText(P);

   /* exit */
   return 0;
} /* end of main */

/* EOF */
