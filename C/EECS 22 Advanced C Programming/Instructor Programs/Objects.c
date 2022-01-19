/* Objects.c: demonstration of objects	*/
/*					*/
/* author: Rainer Doemer		*/
/*					*/
/* modifications:			*/
/* 11/21/04 RD	initial version		*/

#include <stdio.h>

/* main function */

int main(void)
{
   int x = 42;
   int y = 13;
   char s[] = "Hello World!";

   printf("Value   of x    is %d.\n", x);
   printf("Address of x    is %p.\n", &x);
   printf("Size    of x    is %u.\n", sizeof(x));
   printf("Value   of y    is %d.\n", y);
   printf("Address of y    is %p.\n", &y);
   printf("Size    of y    is %u.\n", sizeof(y));
   printf("Value   of s    is %s.\n", s);
   printf("Address of s    is %p.\n", &s);
   printf("Size    of s    is %u.\n", sizeof(s));
   printf("Value   of s[1] is %c.\n", s[1]);
   printf("Address of s[1] is %p.\n", &s[1]);
   printf("Size    of s[1] is %u.\n", sizeof(s[1]));

   return 0;
}

/* EOF */
