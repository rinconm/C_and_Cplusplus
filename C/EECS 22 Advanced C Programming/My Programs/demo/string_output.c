/* Program: demo.c */
/* Purpose: test code */

#include <stdio.h>
//#include <string.h>

#define SLEN 80 /* Max string length */

int main(void)
{
  char usrname[SLEN] = {"Marcos"};

  /* Shouldn't use %s--potential buffer overflow! Then what's best way */
  /* without having too many spaces in printf??????????? */
  
  printf("Hello, %20s! \n", usrname);
  printf("Hello, %s! \n", usrname);

}

/* EOF */
