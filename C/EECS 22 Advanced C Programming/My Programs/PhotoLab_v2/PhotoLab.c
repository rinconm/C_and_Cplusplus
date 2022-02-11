/*********************************************************************/
/* Program: PhotoLab.c: (v2) Assignment 3 for EECS 22, Winter 2022   */
/* Purpose: A menu-driven digital image processing (DIP) program.    */
/*          Performs DIP operations on a specified image within the  */
/*          working directory. The  modified images get saved onto a */
/*          public domain for viewing: http://eecs.uci.edu/~rinconm/ */
/* Authors: Marcos Rincon, EECS22 Teacher's Aid                      */
/*                                                                   */
/* Version History:                                                  */
/* 02/09/22 MR Added Advanced Function Definitions/Algorithms        */
/* 02/02/22 MR Formatting & modularized PhotoLab.c to separate files */
/* 01/24/22 TA Initial Version Template                              */
/*********************************************************************/

#include <stdio.h>
#include "Constants.h"
#include "FileIO.h"
#include "DIPs.h"
#include "Advanced.h"

void PrintMenu(void);

/* Test all functions */
void AutoTest(unsigned char R[WIDTH][HEIGHT],
	      unsigned char G[WIDTH][HEIGHT],
	      unsigned char B[WIDTH][HEIGHT]);

int main(void)
{
  unsigned   char R[WIDTH][HEIGHT];	/* use three 2-D arrays to store R, G, B components */
  unsigned   char G[WIDTH][HEIGHT];
  unsigned   char B[WIDTH][HEIGHT];
              int ChoiceByUser;			/* user input option */
             char fname[SLEN];		/* input file name */
              int rc = -1;			/* return code of ReadImage() initialized */
  /* ColorFilter() parameters */
              int target_r, target_g, target_b, threshold;
           double factor_r, factor_g, factor_b;
  /* AddBorder() parameters */
              int border_width;
             char colorOption[SLEN];
  /* Noise parameter */
              int percentage;
  /* Posterize parameters */
  unsigned    int rbits, gbits, bbits;
  /* Motion Blur parameters */
              int BlurAmount;

  /* DEBUG Mode - Set during compilation (-DDEBUG) */
  #ifdef DEBUG
    AutoTest(R,G,B);
    rc = SUCCESS;	/* set returned code SUCCESS, since image is loaded */
    return 0;
  #endif /* DEBUG */

  /* Default Mode */
  PrintMenu();
  printf("Please make your choice: ");
  scanf("%d", &ChoiceByUser);
  while (ChoiceByUser != EXIT)
  {
    if (ChoiceByUser == 1)
    { 
      printf("Please input the file name to load: ");
      scanf("%75s", fname);
      rc = LoadImage(fname, R, G, B);
    }
    /* menu item 2 - 10 requires image is loaded first */
    else if (ChoiceByUser >= 2 && ChoiceByUser <= 14) 
    {
      if (rc != SUCCESS)	 
      {	printf("No image is read.\n"); }
      /* now image is loaded */
      else
      {
	switch(ChoiceByUser)
	{
	  case 2:
	    printf("Please input the file name to save: ");
	    scanf("%75s", fname);
	    SaveImage(fname, R, G, B);
	    break;
	  case 3:
	    BlackNWhite(R, G, B);
	    printf("\"Black & White\" operation is done!\n");
	    break;
	  case 4:
	    Negative(R,G,B);
	    printf("\"Negative\" operation is done!\n");
	    break;
	  case 5:
	    printf("Enter Red   component for the target color: ");
	    scanf("%d", &target_r);
	    printf("Enter Green component for the target color: ");
	    scanf("%d", &target_g);
	    printf("Enter Blue  component for the target color: ");
	    scanf("%d", &target_b);
	    printf("Enter threshold for the color difference: ");
	    scanf("%d", &threshold);
	    printf("Enter value for Red component in the target color: ");
	    scanf("%lf", &factor_r);
	    printf("Enter value for Green component in the target color: ");
	    scanf("%lf", &factor_g);
	    printf("Enter value for Blue  component in the target color: ");
	    scanf("%lf", &factor_b);
	    ColorFilter(R, G, B, target_r, target_g, target_b, threshold, factor_r, factor_g, factor_b);
	    printf("\"Color Filter\" operation is done!\n");
	    break;
	  case 6:
	    Edge(R, G, B);
	    printf("\"Edge\" operation is done!\n");
	    break;
	  case 7:
	    Shuffle(R, G, B);
	    printf("\"Shuffle\" operation is done!\n");
	    break;
	  case 8:
	    VFlip(R, G, B);
	    printf("\"VFlip\" operation is done!\n");
	    break;
	  case 9:
	    VMirror(R, G, B);
	    printf("\"Vertically Mirror\" operation is done!\n");
	    break;
	  case 10:
	    printf("Enter border width:");
	    scanf("%d", &border_width);
	    printf("Available border colors : black, white, red, green, blue, yellow, cyan, pink, orange\n");
	    printf("Select border color from the options: ");
	    scanf("%s",colorOption);
	    AddBorder(R, G, B, colorOption, border_width);
	    printf("\"Border\" operation is done!\n");
	    break;
	  case 11:
	    printf("Please input noise percentage: ");
	    scanf("%d", &percentage);
	    Noise(percentage, R, G, B);
	    printf("\"Noise\" operation is done!\n");
	    break;
	  case 12:
	    Sharpen(R, G, B);
	    printf("\"Sharpen\" operation is done!\n");
	    break;
	  case 13:
	    printf("Enter the number of posterization bits for R channel (1 to 8): ");
	    scanf("%u", &rbits);
	    printf("Enter the number of posterization bits for G channel (1 to 8): ");
	    scanf("%u", &gbits);
	    printf("Enter the number of posterization bits for B channel (1 to 8): ");
	    scanf("%u", &bbits);
	    Posterize(R, G, B, rbits, gbits, bbits);
	    printf("\"Posterize\" operation is done!\n");
	    break;
	  case 14:
	    printf("Please input blur amount: ");
	    scanf("%d", &BlurAmount);
	    MotionBlur(BlurAmount, R, G, B);
	    printf("\"Motion Blur\" operation is done!\n");
	    break;
	  default:
	    break;
	} /* hctiws */
      } /* esle */
    } /* esle fi */
    else if (ChoiceByUser == 15) 
    {
      AutoTest(R,G,B);
      rc = SUCCESS;	/* set returned code SUCCESS, since image is loaded */
    }
    else
    { printf("Invalid selection!\n"); }
    /* Process finished, waiting for another input */
    PrintMenu();
    printf("Please make your choice: ");
    scanf("%d", &ChoiceByUser);
  } /* elihw */
  printf("You exit the program.\n");
  return 0;
} /* end of main */


/*******************************************/
/* Function implementations should go here */
/*******************************************/

void PrintMenu(void) 
{
  printf("\n----------------------------\n");
  printf(" 1: Load a PPM image\n");
  printf(" 2: Save an image in PPM and JPEG format\n");
  printf(" 3: Change a color image to Black & White\n");
  printf(" 4: Make a negative of an image\n");
  printf(" 5: Color filter an image\n");
  printf(" 6: Sketch the edge of an image\n");
  printf(" 7: Shuffle an image\n");
  printf(" 8: Flip an image vertically\n");
  printf(" 9: Mirror an image vertically\n");
  printf("10: Add border to the image\n");
  printf("11: Add noise to an image\n");
  printf("12: Sharpen an image\n");
  printf("13: Posterize an image\n");
  printf("14: Motion Blur\n");
  printf("15: Test all functions\n");
  printf("16: Exit\n");
} /* end of PrintMenu */


void AutoTest(unsigned char R[WIDTH][HEIGHT],
	      unsigned char G[WIDTH][HEIGHT],
	      unsigned char B[WIDTH][HEIGHT])
{
  char fname[SLEN] = "EngPlaza";

  LoadImage(fname, R, G, B);
  BlackNWhite(R, G, B);
  SaveImage("bw", R, G, B);
  #ifdef DEBUG
     printf("Black & White tested!\n\n");
  #endif /* DEBUG */

  LoadImage(fname, R, G, B);
  Negative(R, G, B);
  SaveImage("negative", R, G, B);
  #ifdef DEBUG
    printf("Negative tested!\n\n");
  #endif /* DEBUG */

  LoadImage(fname, R, G, B);
  ColorFilter(R, G, B, 190, 100, 150, 60, 0, 0, 255);
  SaveImage("colorfilter", R, G, B);
  #ifdef DEBUG
    printf("Color Filter tested!\n\n");
  #endif /* DEBUG */

  LoadImage(fname, R, G, B);
  Edge(R, G, B);
  SaveImage("edge", R, G, B);
  #ifdef DEBUG
    printf("Edge Detection tested!\n\n");
  #endif /* DEBUG */

  LoadImage(fname, R, G, B);
  VMirror(R, G, B);
  SaveImage("vmirror", R, G, B);
  #ifdef DEBUG
    printf("VMirror tested!\n\n");
  #endif /* DEBUG */

  LoadImage(fname, R, G, B);
  VFlip(R, G, B);
  SaveImage("vflip", R, G, B);
  #ifdef DEBUG
    printf("VFlip tested!\n\n");
  #endif /* DEBUG */

  LoadImage(fname, R, G, B);
  Shuffle(R, G, B);
  SaveImage("shuffle", R, G, B);
  #ifdef DEBUG
    printf("Shuffle tested!\n\n");	
  #endif /* DEBUG */

  LoadImage(fname, R, G, B);
  AddBorder (R, G, B, "pink", 64);
  SaveImage("border", R, G, B);
  #ifdef DEBUG
    printf("Border tested!\n\n");
  #endif /* DEBUG */

  LoadImage(fname, R, G, B);
  Noise(30, R, G, B);
  SaveImage("noise", R, G, B);
  #ifdef DEBUG
    printf("Noise tested!\n\n");
  #endif /* DEBUG */

  LoadImage(fname, R, G, B);
  Sharpen(R, G, B);
  SaveImage("sharpen", R, G, B);
  #ifdef DEBUG
    printf("Sharpen tested!\n\n");
  #endif /* DEBUG */

  LoadImage(fname, R, G, B);
  Posterize(R, G, B, 7, 7, 7);
  SaveImage("posterize", R, G, B);
  #ifdef DEBUG
    printf("Posterize tested!\n\n");
  #endif /* DEBUG */

  LoadImage(fname, R, G, B);
  MotionBlur(40, R, G, B);
  SaveImage("blur", R, G, B);
  #ifdef DEBUG
    printf("MotionBlur tested!\n\n");
  #endif /* DEBUG */

} /* end of AutoTest */

/* EOF PhotoLab.c */
