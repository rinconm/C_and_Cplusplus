/*******************************************************************************
 * Program: Custom-Count
 * Purpose: Program prompts user to type in a starting and ending alphabet
 * character and counts either upwards or downwards beginning from the starting
 * character and ending at the ending character in the order in which they
 * appear in the ASCII table.
 *
 * Version History
 * 2021/11/20   Marcos      init version and added if-else statement to either
 *                          count up or down depending on the ascii values
*******************************************************************************/
#include <stdio.h>

// Function: main
// Description: prompt for input, then perform custom count
int main(void)
{
    int counter;                // Intermediate values for count
    char startPoint, endPoint;  // Starting and ending chars for count down

    // Prompt user for inputs
    printf("--- Custom Character Count Program ---\n");
    printf("Enter a starting character: ");
    scanf("%s", &startPoint);
    printf("Enter an ending character: ");
    scanf("%s", &endPoint);

    // Count from first char to second char depending on their ASCII order
    if (startPoint < endPoint)
        for (counter = startPoint; counter <= endPoint; counter++)
            printf("%c\n", counter);
    else
        for (counter = startPoint; counter >= endPoint; counter--)
            printf("%c\n", counter);

    return 0;                   // exit program successfully
}
/* EOF */