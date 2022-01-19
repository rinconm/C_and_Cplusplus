/*********************************************************/
/* Main.c: main program file                             */
/*********************************************************/

#include "Constants.h"
#include "FileIO.h"
#include "Age.h"

int main(void)
{
    unsigned char R[WIDTH][HEIGHT];
    unsigned char G[WIDTH][HEIGHT];
    unsigned char B[WIDTH][HEIGHT];

    if (ReadImage("UCI_Firetrucks.ppm", R, G, B) != 0)
       { return 10; }
    Age(R, G, B);
    if (WriteImage("UCI_Firetrucks_old.ppm", R, G, B) != 0)
       { return 10; }

    return 0;
} /* end of main */

/* EOF Main.c */
