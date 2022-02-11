/*********************************************************************/
/* Program: PhotoLab.c: Assignment 2 for EECS 22, Winter 2022        */
/* Purpose: A menu-driven digital image processing (DIP) program.    */
/*          Performs DIP operations on a specified image within the  */
/*          working directory. The  modified images get saved onto a */
/*          public domain for viewing: http://eecs.uci.edu/~rinconm/ */
/* Authors: Marcos Rincon, Rainer Doemer                             */
/*                                                                   */
/* Version History:                                                  */
/* 01/26/22 MR Added Function Definitions/Algorithms                 */
/* 01/10/22 RD Initial Version Template                              */
/*********************************************************************/

/*** preprocessor directives ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*** global definitions ***/
const int WIDTH  = 512;      /* image width */
const int HEIGHT = 288;      /* image height */
const int SLEN   =  80;      /* max. string length */

/*** function declarations ***/

/* print a menu */
void PrintMenu(void);

/* read image from a file */
int LoadImage(const char fname[SLEN], 
	      unsigned char R[WIDTH][HEIGHT],
	      unsigned char G[WIDTH][HEIGHT], 
	      unsigned char B[WIDTH][HEIGHT]);

/* save a processed image */
int SaveImage(const char fname[SLEN], 
	      unsigned char R[WIDTH][HEIGHT], 
	      unsigned char G[WIDTH][HEIGHT], 
	      unsigned char B[WIDTH][HEIGHT]);

/* change a color image to black & white */
void BlackNWhite(unsigned char R[WIDTH][HEIGHT], 
		 unsigned char G[WIDTH][HEIGHT], 
		 unsigned char B[WIDTH][HEIGHT]);

/* reverse image color */
void Negative(unsigned char R[WIDTH][HEIGHT], 
	      unsigned char G[WIDTH][HEIGHT], 
	      unsigned char B[WIDTH][HEIGHT]);

/* color filter */
void ColorFilter(unsigned char R[WIDTH][HEIGHT], 
		 unsigned char G[WIDTH][HEIGHT],
                 unsigned char B[WIDTH][HEIGHT], 
		 int target_r, int target_g, int target_b, int threshold, 
		 int replace_r, int replace_g, int replace_b);

/* edge detection */
void Edge(unsigned char R[WIDTH][HEIGHT], 
	  unsigned char G[WIDTH][HEIGHT],
          unsigned char B[WIDTH][HEIGHT]);

/* mirror image vertically */
void VMirror(unsigned char R[WIDTH][HEIGHT], 
	     unsigned char G[WIDTH][HEIGHT],
             unsigned char B[WIDTH][HEIGHT]);

/* shuffle the image */
void Shuffle(unsigned char R[WIDTH][HEIGHT], 
	     unsigned char G[WIDTH][HEIGHT],
             unsigned char B[WIDTH][HEIGHT]);


/* add border */
void AddBorder(unsigned char R[WIDTH][HEIGHT], 
	       unsigned char G[WIDTH][HEIGHT],
               unsigned char B[WIDTH][HEIGHT], 
	       char color[SLEN], int border_width);

/* flip image vertically */
void VFlip(unsigned char R[WIDTH][HEIGHT], 
	   unsigned char G[WIDTH][HEIGHT],
           unsigned char B[WIDTH][HEIGHT]);

/* test all functions */
void AutoTest(unsigned char R[WIDTH][HEIGHT], 
	      unsigned char G[WIDTH][HEIGHT], 
	      unsigned char B[WIDTH][HEIGHT]);

int main(void)
{
    /* Two dimensional arrays to hold the current image data, */
    /* one array for each color component.                    */
    unsigned char   R[WIDTH][HEIGHT];
    unsigned char   G[WIDTH][HEIGHT];
    unsigned char   B[WIDTH][HEIGHT];
    int op = 0;                         /* Operation variable */
    char fname [SLEN];                  /* File name variable */
    int imgread = 0;                    /* Indicates if an image has been read (for error purp) */
    int target_r, target_g, target_b;   /* Color values to be replaced for ColorFilter op */
    int threshold;                      /* Defines range of color values for ColorFilter op */
    int replace_r, replace_g, replace_b;/* Color values that will replace */
    int border_width;                   /* Height pixels that will be a border for Border op */
    char color[SLEN];                   /* Color of border for Border op */

    /* Please replace the following code with proper menu with function calls for DIP operations */
    do
    {
      /* Print user menu until user exits program */
      PrintMenu();
      scanf("%d", &op);
      /* Perform an operation depending on user input */
      switch (op)
      {
        case 1: /* LoadImage operation */
	  printf("Please input the file name to load: ");
	  scanf("%79s", fname);
	  LoadImage(fname, R, G, B);
	  imgread = 1;
	  break;
        case 2: /* SaveImage operation */
	  if (imgread == 0)
	  {
	    printf("No image has been read yet! \n");
	    printf("Please load an image first. \n");
	    break;
	  } /* fi */ 
	  printf("Please input the file name to save: ");
	  scanf("%79s", fname);
	  SaveImage(fname, R, G, B);
	  break;
        case 3: /* BlackNWhite operation */
	  if (imgread == 0)
	  {
	    printf("No image has been read yet! \n");
	    printf("Please load an image first. \n");
	    break;
	  } /* fi */ 
	  BlackNWhite(R, G, B);
	  break;
        case 4: /* Negative operation */
	  if (imgread == 0)
	  {
	    printf("No image has been read yet! \n");
	    printf("Please load an image first. \n");
	    break;
	  } /* fi */ 
	  Negative(R, G, B);
	  break;
        case 5: /* ColorFilter operation */
	  if (imgread == 0)
	  {
	    printf("No image has been read yet! \n");
	    printf("Please load an image first. \n");
	    break;
	  } /* fi */ 
	  printf("Enter Red   component for the target color: ");
	  scanf("%d", &target_r);
	  printf("Enter Green component for the target color: ");
	  scanf("%d", &target_g);
	  printf("Enter Blue  component for the target color: ");
	  scanf("%d", &target_b);
	  printf("Enter threshold for the color difference: ");
	  scanf("%d", &threshold);
	  printf("Enter value for Red   component in the target color: ");
	  scanf("%d", &replace_r);
	  printf("Enter value for Green component in the target color: ");
	  scanf("%d", &replace_g);
	  printf("Enter value for Blue  component in the target color: ");
	  scanf("%d", &replace_b);
	  ColorFilter(R, G, B, target_r, target_g, target_b, threshold, replace_r, replace_g, replace_b);
	  break;
        case 6: /* Edge operation */
	  if (imgread == 0)
	  {
	    printf("No image has been read yet! \n");
	    printf("Please load an image first. \n");
	    break;
	  } /* fi */ 
	  Edge(R, G, B);
	  break;
        case 7: /* Shuffle operation */
	  if (imgread == 0)
	  {
	    printf("No image has been read yet! \n");
	    printf("Please load an image first. \n");
	    break;
	  } /* fi */ 
	  Shuffle(R, G, B);
	  break;
        case 8: /* VFlip operation */
	  if (imgread == 0)
	  {
	    printf("No image has been read yet! \n");
	    printf("Please load an image first. \n");
	    break;
	  } /* fi */ 
	  VFlip(R, G, B);
	  break;
        case 9: /* VMirror operation */
	  if (imgread == 0)
	  {
	    printf("No image has been read yet! \n");
	    printf("Please load an image first. \n");
	    break;
	  } /* fi */ 
	  VMirror(R, G, B);
	  break;
        case 10: /* AddBorder operation */
	  if (imgread == 0)
	  {
	    printf("No image has been read yet! \n");
	    printf("Please load an image first. \n");
	    break;
	  } /* fi */ 
	  printf("Enter border width: ");
	  scanf("%d", &border_width);
	  printf("Available border colors : black, white, red, green, blue, yellow, cyan, pink, orange \n");
	  printf("Select border color from the options: ");
	  scanf("%20s", color);
	  AddBorder(R, G, B, color, border_width);
	  break;
        case 11: /* AutoTest operation */
	  AutoTest(R, G, B);
	  break;
        case 12: /* Exit program */
	  printf("Exiting now... \n");
	  break;
        default: /* Invalid input */
	  printf("Please enter a valid operation number! \n");
	  break;
      } /* hctiws */
    } /* od */
      while (op != 12); /* Exit program with input = 12 */
    /* End of replacing */


    return 0;
} /* end of main */

/* read image from a file */
int LoadImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    FILE *File;
    char Type[SLEN];
    int  Width, Height, MaxValue;
    int  x, y;
    char ftype[] = ".ppm";
    char fname_ext[SLEN + sizeof(ftype)];

    strcpy(fname_ext, fname);
    strcat(fname_ext, ftype);

    File = fopen(fname_ext, "r");
    if (!File) {
        printf("\nCannot open file \"%s\" for reading!\n", fname);
        return 1;
    }
    fscanf(File, "%79s", Type);
    if (Type[0] != 'P' || Type[1] != '6' || Type[2] != 0) {
        printf("\nUnsupported file format!\n");
        return 2;
    }
    fscanf(File, "%d", &Width);
    if (Width != WIDTH) {
        printf("\nUnsupported image width %d!\n", Width);
        return 3;
    }
    fscanf(File, "%d", &Height);
    if (Height != HEIGHT) {
        printf("\nUnsupported image height %d!\n", Height);
        return 4;
    }
    fscanf(File, "%d", &MaxValue);
    if (MaxValue != 255) {
        printf("\nUnsupported image maximum value %d!\n", MaxValue);
        return 5;
    }
    if ('\n' != fgetc(File)) {
        printf("\nCarriage return expected!\n");
        return 6;
    }
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            R[x][y] = fgetc(File);
            G[x][y] = fgetc(File);
            B[x][y] = fgetc(File);
        }
    }
    if (ferror(File)) {
        printf("\nFile error while reading from file!\n");
        return 7;
    }
    printf("%s was read successfully!\n", fname_ext);
    fclose(File);
    return 0;
} /* end of LoadImage */

/* save a processed image */
int SaveImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    FILE *File;
    char ftype[] = ".ppm";
    char fname_ext[SLEN + sizeof(ftype)];
    char SysCmd[SLEN * 5];
    int  x, y;

    strcpy(fname_ext, fname);
    strcat(fname_ext, ftype);

    File = fopen(fname_ext, "w");
    if (!File) {
        printf("\nCannot open file \"%s\" for writing!\n", fname);
        return 1;
    }
    fprintf(File, "P6\n");
    fprintf(File, "%d %d\n", WIDTH, HEIGHT);
    fprintf(File, "255\n");

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            fputc(R[x][y], File);
            fputc(G[x][y], File);
            fputc(B[x][y], File);
        }
    }

    if (ferror(File)) {
        printf("\nFile error while writing to file!\n");
        return 2;
    }
    fclose(File);
    printf("%s was saved successfully. \n", fname_ext);

    /*
     * rename file to image.ppm, convert it to ~/public_html/<fname>.jpg
     * and make it world readable
     */
    sprintf(SysCmd, "~eecs22/bin/pnmtojpeg_hw2.tcsh %s", fname_ext);
    if (system(SysCmd) != 0) {
        printf("\nError while converting to JPG:\nCommand \"%s\" failed!\n", SysCmd);
        return 3;
    }
    printf("%s.jpg was stored for viewing. \n", fname);

    return 0;
} /* end of SaveImage */

/**************************************************************/
/* Please add your function definitions here...               */
/**************************************************************/
/* print user menu */
void PrintMenu(void)
{
  printf("_________________________________________\n");
  printf(" 1: Load a PPM image \n");
  printf(" 2: Save an image in PPM and JPEG format \n");
  printf(" 3: Change a color image to Black & White \n");
  printf(" 4: Make a negative of an image \n");
  printf(" 5: Color filter of an image \n");
  printf(" 6: Sketch the edge of an image \n");
  printf(" 7: Shuffle an image \n");
  printf(" 8: Flip an image vertically \n");
  printf(" 9: Mirror an image vertically \n");
  printf("10: Add Border to an image \n");
  printf("11: Test all functions \n");
  printf("12: Exit \n");
  printf("please make your choice: ");
} /* end of PrintMenu */

/* change a color image to black & white */
void BlackNWhite(unsigned char R[WIDTH][HEIGHT], 
		 unsigned char G[WIDTH][HEIGHT], 
		 unsigned char B[WIDTH][HEIGHT])
{
  int gval;          /* greyscale value of pixel */
  int x, y;          /* for loop variables */

  /* Determine grayscal value of each pixel and assign it */
  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      gval = (R[x][y] + G[x][y] + B[x][y]) / 3;
      R[x][y] = gval;
      G[x][y] = gval;
      B[x][y] = gval;
    } /* rof */
  } /* rof */

  printf("\"Black & White\" operation is done! \n");
} /* end of BlackNWhite */

/* reverse image color */
void Negative(unsigned char R[WIDTH][HEIGHT], 
	      unsigned char G[WIDTH][HEIGHT], 
	      unsigned char B[WIDTH][HEIGHT])
{
  int x, y;           /* for loop variables */
  int MaxValue = 255; /* max intensity value */

  /* Invert intensity value of each pixel by subtracting max intensity value
     with pixel value */
  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      R[x][y] = MaxValue - R[x][y];
      G[x][y] = MaxValue - G[x][y];
      B[x][y] = MaxValue - B[x][y];
    } /* rof */
  } /* rof */

  printf("\"Negative\" operation is done! \n");
} /* end of Negative */

/* color filter */
void ColorFilter(unsigned char R[WIDTH][HEIGHT], 
		 unsigned char G[WIDTH][HEIGHT],
                 unsigned char B[WIDTH][HEIGHT], 
		 int target_r, int target_g, int target_b, int threshold, 
		 int replace_r, int replace_g, int replace_b)
{
  int x, y;           /* for loop variables */

  /* Replace a range of color values with the user-defined color value. These  */
  /* parameters are defined by the user before the function call and passed as */
  /* parameters to the function at function call                               */
  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      if   (R[x][y] > target_r - threshold && R[x][y] < target_r + threshold
         && G[x][y] > target_g - threshold && G[x][y] < target_g + threshold
         && B[x][y] > target_b - threshold && B[x][y] < target_b + threshold)
      {
	R[x][y] = replace_r;
	G[x][y] = replace_g;
	B[x][y] = replace_b;
      } /* fi */
    } /* rof */
  } /* rof */

  printf("\"Color Filter\" operation is done! \n");
} /* end of ColorFilter */

/* edge detection */
/* Note: For some reason the modified image has red artifacts on */
/*       right edge of image. Look for solution in the future    */
void Edge(unsigned char R[WIDTH][HEIGHT], 
	  unsigned char G[WIDTH][HEIGHT],
          unsigned char B[WIDTH][HEIGHT])
{
  /* Local two dimensional arrays to copy the current image data,  */
  /* one array for each color component.                           */
  unsigned char RT[WIDTH][HEIGHT]; 
  unsigned char GT[WIDTH][HEIGHT];
  unsigned char BT[WIDTH][HEIGHT];
  int x, y;                        /* for loop variables */
  int temp;                        /* Color Value that will be assigned to each pixel */

  /* Detect edges by mapping each intensity value to a new value, which is the sum of itself and  */
  /* its 8 neighbors with different parameters. Repeat for every pixel and every color channel of */
  /* the image. We use saturated arithmetic to account for values that are out of bounds [0, 255] */
  for (y = 1; y < HEIGHT - 1; y++)
  {
    for (x = 1; x < WIDTH - 1; x++)
    {
      temp = -R[x-1][y-1] - R[x][y-1] - R[x+1][y-1] - R[x-1][y] + (8 * R[x][y]) - R[x+1][y] - R[x-1][y+1] - R[x][y+1] - R[x+1][y+1];
      if (temp > 255)
	temp = 255;
      else if (temp < 0)
	temp = 0;
      RT[x][y] = temp;
      temp = -G[x-1][y-1] - G[x][y-1] - G[x+1][y-1] - G[x-1][y] + (8 * G[x][y]) - G[x+1][y] - G[x-1][y+1] - G[x][y+1] - G[x+1][y+1];
      if (temp > 255)
	temp = 255;
      else if (temp < 0)
	temp = 0;
      GT[x][y] = temp;
      temp = -B[x-1][y-1] - B[x][y-1] - B[x+1][y-1] - B[x-1][y] + (8 * B[x][y]) - B[x+1][y] - B[x-1][y+1] - B[x][y+1] - B[x+1][y+1];
      if (temp > 255)
	temp = 255;
      else if (temp < 0)
	temp = 0;
      BT[x][y] = temp;
    } /* rof */
  } /* rof */

  /* Copy local image array to main image array */
  memcpy(R, RT, sizeof(RT));
  memcpy(G, GT, sizeof(GT));
  memcpy(B, BT, sizeof(BT));

  printf("\"Edge\" operation is done! \n");
} /* end of Edge */

/* mirror image vertically */
void VMirror(unsigned char R[WIDTH][HEIGHT], 
	     unsigned char G[WIDTH][HEIGHT],
             unsigned char B[WIDTH][HEIGHT])
{
  int x, y; /* for loop variables */

  /* Copy each subsequent row of pixels from the top to subsequent rows
     of pixels at the bottom of image */
  for (y = 0; y < HEIGHT/2; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      R[x][HEIGHT-1-y] = R[x][y];
      G[x][HEIGHT-1-y] = G[x][y];
      B[x][HEIGHT-1-y] = B[x][y];
    } /* rof */
  } /* rof */

  printf("\"VMirror\" operation is done! \n");
} /* end of VMirror */

/* shuffle the image */
void Shuffle(unsigned char R[WIDTH][HEIGHT], 
	     unsigned char G[WIDTH][HEIGHT],
             unsigned char B[WIDTH][HEIGHT])
{
  unsigned char RT[WIDTH][HEIGHT]; 
  unsigned char GT[WIDTH][HEIGHT];
  unsigned char BT[WIDTH][HEIGHT];
  int tot_blocks = 16;                       /* Total number of equally sized blocks */
  int block_indx = tot_blocks/4;             /* Blocks across width and height */
  char blocks_moved[block_indx][block_indx]; /* Array to keep track of which blocks have been moved */
  int w_pixl_indx = WIDTH / block_indx;      /* Pixels in the width of a block */
  int h_pixl_indx = HEIGHT / block_indx;     /* Pixels in the height of a block */
  int unsigned rand_w_indx1;                 /* RNG value of width index 1 */
  int unsigned rand_h_indx1;                 /* RNG Value of height index 1 */
  int unsigned rand_w_indx2;                 /* RNG value of width index 2 */
  int unsigned rand_h_indx2;                 /* RNG Value of height index 2 */
  int x, y, a, b;                            /* For loop variables */
  int opdone;                                /* Variable to check if all blocks shuffled */
  int startw1, startw2, starth1, starth2;    /* Initialization values of the for loop variables */
  int endh1, endw1;                          /* Ending values of the for loop variables */

  /* The following line of code is a temporary solution... this line had to be added to initialize this  */
  /* array value to 0 for the AutoTest op to function properly. For unkown reasons this value is not set */
  /* to 0 when Shuffle is called within the AutoTest op. :/                                              */
  blocks_moved[0][1] = 0;

  /* Copy all pixel values of main image array to local image array */
   memcpy(RT, R, sizeof(RT));
   memcpy(GT, G, sizeof(GT));
   memcpy(BT, B, sizeof(BT));

  /* Use current time as seed for random generator. Ensures random shuffle
     at every program runtime. */
  srand(time(0));

  /* Repeat shuffling until all blocks have been moved */
  do
  {
    /* Random Number Generator (RNG) Values: 0-3 for width and height index values of the blocks */
    /* that will be shuffled. Will then mark those blocks as moved in blocks_moved array.        */
    do
    {
      rand_w_indx1 = rand() % 4;
      rand_h_indx1 = rand() % 4;
    } /* od */
      while (blocks_moved[rand_w_indx1][rand_h_indx1] != 0);
    blocks_moved[rand_w_indx1][rand_h_indx1] = 1;
    do
    {
      rand_w_indx2 = rand() % 4;
      rand_h_indx2 = rand() % 4;
    } /* od */
      while (blocks_moved[rand_w_indx2][rand_h_indx2] != 0);
    blocks_moved[rand_w_indx2][rand_h_indx2] = 1;

    /* Switch the pixel values of the first block with the second block */
    starth1 = rand_h_indx1 * h_pixl_indx;
    starth2 = rand_h_indx2 * h_pixl_indx;
    endh1 = (rand_h_indx1 + 1) * h_pixl_indx;
    startw1 = rand_w_indx1 * w_pixl_indx;
    startw2 = rand_w_indx2 * w_pixl_indx;
    endw1 = (rand_w_indx1 + 1) * w_pixl_indx;
    for (y = starth1, b = starth2; y < endh1; y++, b++)
    {
      for (x = startw1, a = startw2; x < endw1; x++, a++)
      {
    	R[x][y] = RT[a][b];
    	G[x][y] = GT[a][b];
    	B[x][y] = BT[a][b];
    	R[a][b] = RT[x][y];
    	G[a][b] = GT[x][y];
    	B[a][b] = BT[x][y];
      } /* rof */
    } /* rof */ 

    /* Determine if all blocks have been shuffled */
    opdone = 1; /* Initialization (will be set to 0 if not done) */
    for (y = 0; y < block_indx; y++)
    {
      for (x = 0; x < block_indx; x++)
      {
       	if (blocks_moved[x][y] == 0)
	  opdone = 0; /* fi */
      } /* rof */
    } /* rof */
  } /* od */
    while (opdone != 1);

  printf("\"Shuffle\" operation is done! \n");
} /* end of Shuffle */

/* add border */
void AddBorder(unsigned char R[WIDTH][HEIGHT], 
	       unsigned char G[WIDTH][HEIGHT],
               unsigned char B[WIDTH][HEIGHT], 
	       char color[SLEN], int border_width)
{
  /* Color values of desired border. One value for each color component. */
  unsigned char RT = 0; 
  unsigned char GT = 0;
  unsigned char BT = 0;
  int x, y;                     /* for loop variables */
  int border_width2;            /* width border (passed border_width is for height) */

  /* Adjust width border for 16:9 ratio */
  border_width2 = border_width * 9/16;

  /* Assign border color depending on user input. The color is defined by the user
     before the function call and passed as a string parameter to the function at
     function call */ 
  if (0 == strcmp(color,"black"))
  {} /* fi */
  else if (0 == strcmp(color,"white"))
  {
    RT = 255;
    GT = 255;
    BT = 255;
  } /* fi esle */
  else if (0 == strcmp(color,"red"))
    RT = 255; /* fi esle */
  else if (0 == strcmp(color,"green"))
    GT = 255; /* fi esle */
  else if (0 == strcmp(color,"blue"))
    BT = 255; /* fi esle */
  else if (0 == strcmp(color,"yellow"))
  {
    RT = 255;
    GT = 255;
  } /* fi esle */
  else if (0 == strcmp(color,"cyan"))
  {
    GT = 255;
    BT = 255;
  } /* fi esle */
  else if (0 == strcmp(color,"pink"))
  {
    RT = 255;
    BT = 255;
  } /* fi esle */
  else if (0 == strcmp(color,"orange"))
  {
    RT = 255;
    GT = 165;
  } /* fi esle */
  else
  {
    printf("That is not a valid color option! \n");
    return;
  } /* esle */

  /* Assign color value to border pixels  while maintaining a 16:9 ratio. */
  /* I can optimize this to use less for loops... consider in the future  */
  for (y = 0; y < border_width/2; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      R[x][y] = RT;
      G[x][y] = GT;
      B[x][y] = BT;
    } /* rof */
  } /* rof */
  for (y = HEIGHT-1; y > HEIGHT-border_width/2; y--)
  {
    for (x = 0; x < WIDTH; x++)
    {
      R[x][y] = RT;
      G[x][y] = GT;
      B[x][y] = BT;
    } /* rof */
  } /* rof */
  for (y = 0+border_width/2; y <= HEIGHT-border_width/2; y++)
  {
    for (x = 0; x < border_width2/2; x++)
    {
      R[x][y] = RT;
      G[x][y] = GT;
      B[x][y] = BT;
    } /* rof */
  } /* rof */
  for (y = 0+border_width/2; y <= HEIGHT-border_width/2; y++)
  {
    for (x = WIDTH-1-border_width2/2; x < WIDTH; x++)
    {
      R[x][y] = RT;
      G[x][y] = GT;
      B[x][y] = BT;
    } /* rof */
  } /* rof */

  printf("\"AddBorder\" operation is done! \n");
} /* end of AddBorder */

/* flip image vertically */
void VFlip(unsigned char R[WIDTH][HEIGHT], 
	   unsigned char G[WIDTH][HEIGHT],
           unsigned char B[WIDTH][HEIGHT])
{
  /* Local two dimensional arrays to copy the current image data, */
  /* one array for each color component.                          */
  unsigned char RT[WIDTH][HEIGHT]; 
  unsigned char GT[WIDTH][HEIGHT];
  unsigned char BT[WIDTH][HEIGHT];
  int x, y;                         /* for loop variables */

  /* Copy each row of pixels starting from the bottom row to the */
  /* each row of pixels of the local array starting from the top */
  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      RT[x][y] = R[x][HEIGHT-1-y];
      GT[x][y] = G[x][HEIGHT-1-y];
      BT[x][y] = B[x][HEIGHT-1-y];
    } /* rof */
  } /* rof */

  /* Copy local image array to main image array */
  memcpy(R, RT, sizeof(RT));
  memcpy(G, GT, sizeof(GT));
  memcpy(B, BT, sizeof(BT));

  printf("\"VFlip\" operation is done! \n");
} /* end of VFlip */

/* test all functions */
void AutoTest(unsigned char R[WIDTH][HEIGHT], 
	      unsigned char G[WIDTH][HEIGHT], 
	      unsigned char B[WIDTH][HEIGHT])
{
  char fname[80] = "EngPlaza"; /* image file to test w/o extension */
  
  /* Test BlackNWhite Function */
  LoadImage(fname, R, G, B);
  BlackNWhite(R, G, B);
  SaveImage("bw", R, G, B);
  printf("Black and White tested!\n\n");

  /* Test Negative Function */
  LoadImage(fname, R, G, B);
  Negative(R, G, B);
  SaveImage("negative", R, G, B);
  printf("Negative tested!\n\n");

  /* Test ColorFilter Function */
  LoadImage(fname, R, G, B);
  ColorFilter(R, G, B, 190, 100, 150, 60, 0, 0, 255);
  SaveImage("colorfilter", R, G, B);
  printf("Color Filter tested!\n\n");

  /* Test Edge Function */
  LoadImage(fname, R, G, B);
  Edge(R, G, B);
  SaveImage("edge", R, G, B);
  printf("Edge tested!\n\n");

  /* Test Shuffle Function */
  LoadImage(fname, R, G, B);
  Shuffle(R, G, B);
  SaveImage("shuffle", R, G, B);
  printf("Shuffle tested!\n\n");

  /* Test VFlip Function */
  LoadImage(fname, R, G, B);
  VFlip(R, G, B);
  SaveImage("vflip", R, G, B);
  printf("VFlip tested!\n\n");

  /* Test VMirror Function */
  LoadImage(fname, R, G, B);
  VMirror(R, G, B);
  SaveImage("vmirror", R, G, B);
  printf("VMirror tested!\n\n");

  /* Test AddBorder Function */
  LoadImage(fname, R, G, B);
  AddBorder(R, G, B, "orange", 64);
  SaveImage("border", R, G, B);
  printf("AddBorder tested!\n\n");

  printf("\"AutoTest\" operation is done! \n");
} /* end of AutoTest */


/* EOF */
