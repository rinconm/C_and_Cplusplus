/*********************************************************************/
/* Program: Advanced.c                                               */
/* Purpose: Function definitions of the advanced Digital Image       */
/*          Processing functions                                     */
/* Authors: Marcos Rincon, EECS 22 Teacher's Aid                     */
/*                                                                   */
/* Version History:                                                  */
/* 02/09/22 MR Function definitions                                  */
/* 02/02/22 MR Formatted & modularized to separate source code file  */
/* 01/24/22 TA Function declarations                                 */
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Advanced.h"

/* add noise to an image */
void Noise(          int percentage,
	   unsigned char R[WIDTH][HEIGHT],
	   unsigned char G[WIDTH][HEIGHT],
	   unsigned char B[WIDTH][HEIGHT])
{
  int noise_pixels = percentage * WIDTH * HEIGHT / 100;
  int x, y;
  int i;

  /* Initialize the random number generator with the current time as the seed */
  srand(time(NULL));
  for (i = 0; i < noise_pixels; i++)
  {
    /* Generate a random pixel */  
    x = rand() % WIDTH;
    y = rand() % HEIGHT;
    R[x][y] = G[x][y] = B[x][y] = MAX_PIXEL;
  } /* rof */
} /* end of Noise */

/* sharpen the image */
void Sharpen(unsigned char R[WIDTH][HEIGHT],
	     unsigned char G[WIDTH][HEIGHT],
	     unsigned char B[WIDTH][HEIGHT])
{
            int x, y, m, n, a, b;
  unsigned char tmpR[WIDTH][HEIGHT];
  unsigned char tmpG[WIDTH][HEIGHT];
  unsigned char tmpB[WIDTH][HEIGHT];

  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      tmpR[x][y] = R[x][y];
      tmpG[x][y] = G[x][y];
      tmpB[x][y] = B[x][y];
    } /* rof */
  } /* rof */
  int sumR = 0;   /* sum of the intensity differences with neighbors */
  int sumG = 0;
  int sumB = 0;
  /* Sharpen the image by first detecting the edges by mapping each intensity */
  /* value to a new value (exactly like Edge function) and then adding the    */
  /* original image to the 'edge' image                                       */
  for (y = 1; y < HEIGHT - 1; y++)
  {
    for (x = 1; x < WIDTH - 1; x++)
    {
      /* Determine a temporary intensity value for each color channel which is */
      /* the sum of eight times itself minus its eight surrounding neighbors   */
      for (n = -1; n <= 1; n++)
      {
	for (m = -1; m <= 1; m++)
	{
	  a = (x + m >= WIDTH) ? WIDTH - 1 : (x + m < 0) ? 0 : x + m;
	  b = (y + n >= HEIGHT) ? HEIGHT - 1 : (y + n < 0) ? 0 : y + n;
	  sumR += (tmpR[x][y] - tmpR[a][b]);
	  sumG += (tmpG[x][y] - tmpG[a][b]);
	  sumB += (tmpB[x][y] - tmpB[a][b]);
	} /* rof */
      } /* rof */
      /* Add an extra intensity value to sharpen image */
      sumR += tmpR[x][y];
      sumG += tmpG[x][y];
      sumB += tmpB[x][y];
      /* Determine if the sum of each intensity value is over or under the */
      /* max and min values. If so, truncate to the max or min value and   */
      /* assign to every color channel. Then initialize sums back to zero  */
      R[x][y] = (sumR > MAX_PIXEL) ? MAX_PIXEL: (sumR < MIN_PIXEL) ? MIN_PIXEL: sumR;
      G[x][y] = (sumG > MAX_PIXEL) ? MAX_PIXEL: (sumG < MIN_PIXEL) ? MIN_PIXEL: sumG;
      B[x][y] = (sumB > MAX_PIXEL) ? MAX_PIXEL: (sumB < MIN_PIXEL) ? MIN_PIXEL: sumB;
      sumR = sumG = sumB = 0;
    } /* rof */
  } /* rof */
} /* end of Sharpen */

/* posterize the image */
void Posterize(unsigned char R[WIDTH][HEIGHT],
	       unsigned char G[WIDTH][HEIGHT],
	       unsigned char B[WIDTH][HEIGHT],
	       unsigned  int rbits,
	       unsigned  int gbits,
	       unsigned  int bbits)
{
  int x, y, sub = 0;
  unsigned int rbitmask1 = MAX_PIXEL, rbitmask2 = MAX_PIXEL;
  unsigned int gbitmask1 = MAX_PIXEL, gbitmask2 = MAX_PIXEL;
  unsigned int bbitmask1 = MAX_PIXEL, bbitmask2 = MAX_PIXEL;

  /* Prepare rbitmask1 to set the nth bit of R[][] to zero */
  for (x = 1; x <= rbits; x++)
  {
    if (x==1)
    {
      sub = 1;
      continue;
    }
    sub += sub;
  }
  rbitmask1 -= sub;
  /* Prepare gbitmask1 to set the nth bit of G[][] to zero */
  for (x = 1; x <= gbits; x++)
  {
    if (x==1)
    {
      sub = 1;
      continue;
    }
    sub += sub;
  }
  gbitmask1 -= sub;
  /* Prepare bbitmask1 to set the nth bit of B[][] to zero */
  for (x = 1; x <= gbits; x++)
  {
    if (x==1)
    {
      sub = 1;
      continue;
    }
    sub += sub;
  }
  bbitmask1 -= sub;
  /* Prepare bitmask2s to set the n-1 bits of R[][], G[][], B[][] to one */
  rbitmask2 = rbitmask2 >> (MAX_BITS + 1 - rbits);
  gbitmask2 = gbitmask2 >> (MAX_BITS + 1 - gbits);
  bbitmask2 = bbitmask2 >> (MAX_BITS + 1 - bbits);

  /* Posterize the image by bit manipulating the orignal RGB array with the bitmasks */
  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      R[x][y] = R[x][y] & rbitmask1;
      R[x][y] = R[x][y] | rbitmask2;
      G[x][y] = G[x][y] & gbitmask1;
      G[x][y] = G[x][y] | gbitmask2;
      B[x][y] = B[x][y] & bbitmask1;
      B[x][y] = B[x][y] | bbitmask2;
    } /* rof */
  } /* rof */
} /* end of Posterize */

/* motion blur */
void MotionBlur(          int BlurAmount,
		unsigned char R[WIDTH][HEIGHT],
		unsigned char G[WIDTH][HEIGHT],
		unsigned char B[WIDTH][HEIGHT])
{
            int x, y, m; /* For loop variables */
            int pixelCount; /* Pixels that will account for the blurring */
  /* Sum of the average intensity value of right pixel neighbors */
  unsigned  int avgR = 0, avgG = 0, avgB = 0;
  /* Temporay RGB values to assign the blur intensity value to each color channel */
  unsigned char tempR = 0;
  unsigned char tempG = 0;
  unsigned char tempB = 0;

  /* Calculate and assign the motion blur intensity value of each color channel  */
  for (y = 0; y < HEIGHT; y++)
  {
    pixelCount = BlurAmount;
    for (x = 0; x < WIDTH - 1; x++)
    {
      /* Initialize average pixel value for every new pixel */
      avgR = 0;
      avgG = 0;
      avgB = 0;
      /* First half of the blur intensity value comes from the original pixel itself */
      tempR = (R[x][y] / 2);
      tempG = (G[x][y] / 2);
      tempB = (B[x][y] / 2);
      /* adjust pixelCount when arriving at edge pixels */
      if(WIDTH - 1 - x < pixelCount)
      {	pixelCount -= 1; }
      /* Second half of the blur intensity value comes from the average intensity   */
      /* values of neighbor pixels of each color channel                            */
      for (m = 1; m  < (WIDTH - x) && m <= pixelCount; m++)
      {
       	avgR += R[x+m][y];
	avgG += G[x+m][y];
	avgB += B[x+m][y];
      } /* rof */
      avgR /= pixelCount;
      avgG /= pixelCount;
      avgB /= pixelCount;      
      tempR += (avgR / 2);
      tempG += (avgG / 2);
      tempB += (avgB / 2);
      /* Assign Motion Blur Intensity Value to each color channel */
      R[x][y] = tempR;
      G[x][y] = tempG;
      B[x][y] = tempB;
    } /* rof */
  } /* rof */
} /* end of MotionBlur */

/* EOF Advanced.c */
