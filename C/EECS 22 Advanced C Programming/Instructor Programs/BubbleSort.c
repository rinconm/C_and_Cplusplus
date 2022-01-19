/* BubbleSort.c: sort strings alphabetically	*/
/*						*/
/* author: Rainer Doemer			*/
/*						*/
/* modifications:				*/
/* 11/06/04 RD	initial version			*/

#include <stdio.h>

/* constant definitions */

#define NUM 10	/* ten strings  */
#define LEN 20	/* of length 20 */

/* function declarations */

void EnterText(char Text[NUM][LEN]);
void PrintText(char Text[NUM][LEN]);
int CompareStrings(char s1[LEN], char s2[LEN]);
void SwapStrings(char s1[LEN], char s2[LEN]);
void BubbleSort(char Text[NUM][LEN]);

/* function definitions */

/* let the user enter the text array		*/

void EnterText(char Text[NUM][LEN])
{
   int i;

   for(i = 0; i < NUM; i++)
      { printf("Enter text string %2d: ", i+1);
	scanf("%19s", Text[i]);
       } /* rof */
} /* end of EnterText */

/* print the text array on the screen		*/

void PrintText(char Text[NUM][LEN])
{
   int i;

   for(i = 0; i < NUM; i++)
      { printf("String %2d: %s\n", i+1, Text[i]);
       } /* rof */
} /* end of PrintText */

/* alphabetically compare strings s1 and s2:	*/
/* return -1, if string s1 < string s2		*/
/* return  0, if string s1 = string s2		*/
/* return  1, if string s1 > string s2		*/

int CompareStrings(char s1[LEN], char s2[LEN])
{
   int i;

   for(i = 0; i < LEN; i++)
      { if (s1[i] > s2[i])
	   { return(1); }
	if (s1[i] < s2[i])
	   { return(-1); }
	if (s1[i] == 0 || s2[i] == 0)
	   { break; }
       } /* rof */
   return 0;
} /* end of CompareStrings */

/* swap/exchange the strings s1 and s2 in place	*/

void SwapStrings(char s1[LEN], char s2[LEN])
{
   int  i;
   char c;

   for(i = 0; i < LEN; i++)
      { c = s1[i];
	s1[i] = s2[i];
	s2[i] = c;
       } /* rof */
} /* end of SwapStrings */

/* sort the text array by comparing every pair	*/
/* of strings; if the pair of strings is not in	*/
/* alphabetical order, swap it			*/

void BubbleSort(char Text[NUM][LEN])
{
   int i, j;

   for(i = 0; i < NUM-1; i++)
      { for(j = i+1; j < NUM; j++)
	   { if (CompareStrings(Text[i], Text[j]) > 0)
		{ SwapStrings(Text[i], Text[j]);
		 } /* fi */
	    } /* rof */
       } /* rof */
} /* end of BubbleSort */

/* main function: enter, sort, print the text	*/

int main(void)
{
   /* local variables */
   char Text[NUM][LEN]; /* NUM strings, length LEN */

   /* input section */
   EnterText(Text);

   /* computation section */
   BubbleSort(Text);

   /* output section */
   PrintText(Text);

   /* exit */
   return 0;
} /* end of main */

/* EOF */
