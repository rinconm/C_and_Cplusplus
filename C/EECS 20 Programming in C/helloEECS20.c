// Program: helloEECS20.c
// Purpose: Greets user after inputting name
// 
// Version History:
// <11-20-21>	Marcos Rincon	init version
#include <stdio.h>

// main function - prints a hello message
int main(void)
{
    char name[25];

    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello %s\n", name);
    return 0;
}
/* EOF */






