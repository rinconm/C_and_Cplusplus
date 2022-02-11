/*********************************************************************/
/* Program: DIPs.c                                                   */
/* Purpose: Function definitions of the standard Digital Image       */
/*          Processing functions                                     */
/* Authors: Marcos Rincon, EECS22 Teacher's Aid                      */
/*                                                                   */
/* Version History:                                                  */
/* 02/02/22 MR Formatted & modularized to separate source code file  */
/* 01/24/22 TA Function declarations                                 */
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "DIPs.h"

/* Example of DIP: YOU WONT CALL THIS FUNCTION */
/* age the image to make it look like old picture */
void Aging(unsigned char R[WIDTH][HEIGHT],
	   unsigned char G[WIDTH][HEIGHT],
	   unsigned char B[WIDTH][HEIGHT])
{
  int x, y;
  for(y = 0; y < HEIGHT; y++ )
  {
    for(x = 0; x < WIDTH; x++ ) 
    {
      B[x][y] = (R[x][y] + G[x][y] + B[x][y]) / 5;
      R[x][y] = (unsigned char) (B[x][y] * 1.6);
      G[x][y] = (unsigned char) (B[x][y] * 1.6);
    } /* rof */
  } /* rof */
} /* end of Aging */

/* make the picture color black & white */
void BlackNWhite(unsigned char R[WIDTH][HEIGHT],
		 unsigned char G[WIDTH][HEIGHT],
		 unsigned char B[WIDTH][HEIGHT])
{
  int x, y, tmp;

  for (y = 0; y < HEIGHT; y++)
  {   
    for (x = 0; x < WIDTH; x++) 
    {
      tmp = (R[x][y] + G[x][y] + B[x][y]) / 3;
      R[x][y] = G[x][y] = B[x][y] = tmp;
    } /* rof */
  } /* rof */
} /* end of BlackNWhite */

/* reverse image color */
void Negative(unsigned char R[WIDTH][HEIGHT],
	      unsigned char G[WIDTH][HEIGHT],
	      unsigned char B[WIDTH][HEIGHT])
{
  int x, y;
  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      R[x][y] = MAX_PIXEL - R[x][y];
      G[x][y] = MAX_PIXEL - G[x][y];
      B[x][y] = MAX_PIXEL - B[x][y];
    } /* rof */
  } /* rof */
} /* end of Negative */

void ColorFilter (unsigned char R[WIDTH][HEIGHT],
		  unsigned char G[WIDTH][HEIGHT],
		  unsigned char B[WIDTH][HEIGHT],
		            int target_r,
		            int target_g,
		            int target_b, 
		            int threshold,
		            int replace_r,
		            int replace_g,
		            int replace_b)
{
  int x, y;

  replace_r = (replace_r > MAX_PIXEL)? MAX_PIXEL : (replace_r < 0) ? 0 : replace_r;
  replace_g = (replace_g > MAX_PIXEL)? MAX_PIXEL : (replace_g < 0) ? 0 : replace_g;
  replace_r = (replace_b > MAX_PIXEL)? MAX_PIXEL : (replace_b < 0) ? 0 : replace_b;

  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      if (   abs(R[x][y] - target_r) <= threshold
	  && abs(G[x][y] - target_g) <= threshold
	  && abs(B[x][y] - target_b) <= threshold)
      {
	R[x][y] = replace_r;
	G[x][y] = replace_g;
	B[x][y] = replace_b;
      } /* fi */
    } /* rof */
  } /* rof */
} /* end of ColorFilter */

void Edge(unsigned char R[WIDTH][HEIGHT],
	  unsigned char G[WIDTH][HEIGHT],
	  unsigned char B[WIDTH][HEIGHT])
{
            int   x, y, m, n, a, b;
  unsigned char   tmpR[WIDTH][HEIGHT];
  unsigned char   tmpG[WIDTH][HEIGHT];
  unsigned char   tmpB[WIDTH][HEIGHT];

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
  /* Detect edges by mapping each intensity value to a new value */
  for (y = 1; y < HEIGHT - 1; y++)
  {
    for (x = 1; x < WIDTH - 1; x++)
    {
      /* Determine the new intensity value for each color channel which is   */
      /* the sum of eight times itself minus its eight surrounding neighbors */
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
      /* Determine if the sum of each intensity value is over or under the */
      /* max and min values. If so, truncate to the max or min value and   */
      /* assign to every color channel. Then initialize sums back to zero  */
      R[x][y] = (sumR > MAX_PIXEL) ? MAX_PIXEL: (sumR < MIN_PIXEL) ? MIN_PIXEL: sumR;
      G[x][y] = (sumG > MAX_PIXEL) ? MAX_PIXEL: (sumG < MIN_PIXEL) ? MIN_PIXEL: sumG;
      B[x][y] = (sumB > MAX_PIXEL) ? MAX_PIXEL: (sumB < MIN_PIXEL) ? MIN_PIXEL: sumB;
      sumR = sumG = sumB = 0;
    } /* rof */
  } /* rof */
  /* set all four borders to 0 */
  for (y = 0; y < HEIGHT; y++)
  {
    R[0][y] = 0;
    G[0][y] = 0;
    B[0][y] = 0;
    R[WIDTH - 1][y] = 0;
    G[WIDTH - 1][y] = 0;
    B[WIDTH - 1][y] = 0;
  } /* rof */
  for (x = 0; x < WIDTH; x++)
  {
    R[x][0] = 0;
    G[x][0] = 0;
    B[x][0] = 0;
    R[x][HEIGHT - 1] = 0;
    G[x][HEIGHT - 1] = 0;
    B[x][HEIGHT - 1] = 0;
  } /* rof */
} /* end of Edge */

/* flip image vertically */
void VFlip(unsigned char R[WIDTH][HEIGHT],
	   unsigned char G[WIDTH][HEIGHT],
	   unsigned char B[WIDTH][HEIGHT])
{
            int x, y;
  unsigned char r, g, b;

  for (y = 0; y < HEIGHT/2; y ++) 
  {
    for (x = 0; x < WIDTH; x ++) 
    {
      r = R[x][HEIGHT - 1 - y];
      g = G[x][HEIGHT - 1 - y];
      b = B[x][HEIGHT - 1 - y];
      R[x][HEIGHT - 1 - y] = R[x][y];
      G[x][HEIGHT - 1 - y] = G[x][y];
      B[x][HEIGHT - 1 - y] = B[x][y];
      R[x][y] = r;
      G[x][y] = g;
      B[x][y] = b;
    } /* rof */
  } /* rof */
} /* end of VFlip */

/* mirror image vertically */
void VMirror(unsigned char R[WIDTH][HEIGHT],
	     unsigned char G[WIDTH][HEIGHT],
	     unsigned char B[WIDTH][HEIGHT])
{
  int x, y;
  for (y = 0; y < HEIGHT / 2; y ++)
  {
    for (x = 0; x < WIDTH; x ++)
    {
      R[x][HEIGHT - 1 - y] = R[x][y];
      G[x][HEIGHT - 1 - y] = G[x][y];
      B[x][HEIGHT - 1 - y] = B[x][y];
    } /* rof */
  } /* rof */
} /* end of VMirror */


/* Shuffle the image */
void Shuffle(unsigned char R[WIDTH][HEIGHT],
	     unsigned char G[WIDTH][HEIGHT],
	     unsigned char B[WIDTH][HEIGHT])
{
  int block_cnt = SHUFF_HEIGHT_DIV * SHUFF_WIDTH_DIV;
  int block_width = WIDTH/SHUFF_WIDTH_DIV;
  int block_height = HEIGHT/SHUFF_HEIGHT_DIV;
  int block[SHUFF_WIDTH_DIV][SHUFF_HEIGHT_DIV];
  int i, j;

  srand(time(NULL));
  /* Initialize block markers to not done (-1) */
  for (i = 0; i < SHUFF_WIDTH_DIV; i++)
  {
    for (j = 0; j< SHUFF_HEIGHT_DIV; j++)
    {
      block[i][j] = -1;
    } /* rof */
  } /* rof */

  while (block_cnt > 0)
  {
    /* Generate a random pair of blocks */
    int dest_height = rand() % SHUFF_HEIGHT_DIV;
    int dest_width = rand() % SHUFF_WIDTH_DIV;
    int src_height = rand() % SHUFF_HEIGHT_DIV;
    int src_width = rand() % SHUFF_WIDTH_DIV;
    /* Check if these blocks are already swaped, if not swap blocks */
    if ((block[dest_width][dest_height] == -1) && (block[src_width][src_height] == -1))
    {
      /* Swap blocks */
      for (i = 0; i < block_height; i++)
      {
	/* Init src and dest height offset */
	int h_dest = ((dest_height * block_height) + i) % HEIGHT;
	int h_src  = ((src_height * block_height) + i) % HEIGHT; 
	for (j = 0; j < block_width; j++)
	{
	  int temp;
	  /* Init src and dest width offset */
	  int w_src  = ((src_width * block_width) + j) % WIDTH; 
	  int w_dest = ((dest_width * block_width) + j) % WIDTH;
	  temp = R[w_dest][h_dest];
	  R[w_dest][h_dest] = R[w_src][h_src];
	  R[w_src][h_src] = temp;
	  temp = G[w_dest][h_dest];
	  G[w_dest][h_dest] = G[w_src][h_src];
	  G[w_src][h_src] = temp;
	  temp = B[w_dest][h_dest];
	  B[w_dest][h_dest] = B[w_src][h_src];
	  B[w_src][h_src] = temp;
	} /* rof */
      } /* rof */
      /* Set marker as done */
      block[dest_width][dest_height] = 1;
      block[src_width][src_height] = 1;
      /* Decrease block count */
      block_cnt -= 2; /* Two blocks are swapped */
    } /* fi */
  } /* elihw */
} /* end of Shuffle */

/* add border to the image */
void AddBorder(unsigned char R[WIDTH][HEIGHT],
	       unsigned char G[WIDTH][HEIGHT],
	       unsigned char B[WIDTH][HEIGHT],
	                char color[SLEN],
	                 int border_width)
{
        int x, y;
        int border_r = 255;
        int border_g = 255;
        int border_b = 255;
  const int X_BORDER_WIDTH = border_width * 9 / 16;
  if (!strcmp(color, "black"))
  {
    border_r = 0;
    border_g = 0;
    border_b = 0;
  }
  else if (!strcmp(color, "white"))
  {
    border_r = 255;
    border_g = 255;
    border_b = 255;
  }
  else if (!strcmp(color, "red"))
  {
    border_r = 255;
    border_g = 0;
    border_b = 0;
  }
  else if (!strcmp(color, "green"))
  {
    border_r = 0;
    border_g = 255;
    border_b = 0;
  }
  else if (!strcmp(color, "blue"))
  {
    border_r = 0;
    border_g = 0;
    border_b = 255;
  }
  else if (!strcmp(color, "yellow"))
  {
    border_r = 255;
    border_g = 255;
    border_b = 0;
  }
  else if (!strcmp(color, "cyan"))
  {
    border_r = 0;
    border_g = 255;
    border_b = 255;
  }
  else if (!strcmp(color, "pink"))
  {
    border_r = 255;
    border_g = 192;
    border_b = 203;
  }
  else if (!strcmp(color, "orange"))
  {
    border_r = 255;
    border_g = 165;
    border_b = 0;
  }
  else
  {
    printf("Unsupported color.\n");
    return;
  }
  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      if ((y < border_width) || (y > HEIGHT - 1 - border_width) ||
	  (x < X_BORDER_WIDTH) || (x > WIDTH - 1 - X_BORDER_WIDTH))
      {
	R[x][y] = border_r;
	G[x][y] = border_g;
	B[x][y] = border_b;
      } /* fi */
    } /* rof */
  } /* rof */
} /* end of AddBorder */

/* EOF DIPS.c */
