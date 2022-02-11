#include "Aging.h"
#include "Global.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Aging(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]) {
    int x, y;
    for(y = 0; y < HEIGHT; y++ ) {
        for(x = 0; x < WIDTH; x++ ) {
            B[x][y] = (R[x][y] + G[x][y] + B[x][y]) / 5;
            R[x][y] = (unsigned char) (B[x][y] * 1.6);
            G[x][y] = (unsigned char) (B[x][y] * 1.6);
        }
    }
}
