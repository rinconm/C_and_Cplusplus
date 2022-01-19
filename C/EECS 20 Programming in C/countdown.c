/**********************************************
 * Countdown, our first C program (based off Figure 11.3 from Patt book)
 *
 * Program prompts user to type in a positive int
 * and counts down from that number to 0
 * displaying each number along the way.
 *
 * Version History
 * 2021/11/15   QV      init version & added return for main/simplified comments
**********************************************/
#include <stdio.h>
#define STOP 0

// Function: main
// Description: prompt for input, then count down
int main(void)
{
    int counter;    // intermediate values for count
    int startPoint; // Starting point for count down

    // Prompt user for input
    printf("----- Countdown Program -----\n");
    printf("Enter a positive integer: ");
    scanf("%d", &startPoint);

    // Count down from the input number to 0
    for (counter = startPoint; counter >= STOP; counter--)
        printf("%d\n", counter);

    // exit program successfully
    return 0;
}
/* EOF */