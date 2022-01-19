/*********************************************************************/
/* PhotoLab.c: final assignment for EECS 10 in Summer 2013           */
/*                                                                   */
/* modifications: (most recent first)                                */
/* 09/02/13 RD	adjusted for lecture usage                           */
/*********************************************************************/

/*** header files ***/

#include <stdio.h>
#include <stdlib.h>

/*** global definitions ***/

#define WIDTH  640	/* image width */
#define HEIGHT 410	/* image height */
#define SLEN    80	/* max. string length */

/*** function declarations ***/

int WriteImage(char Filename[SLEN],
              unsigned char R[WIDTH][HEIGHT],
              unsigned char G[WIDTH][HEIGHT],
              unsigned char B[WIDTH][HEIGHT]);

int ReadImage(char Filename[SLEN],
              unsigned char R[WIDTH][HEIGHT],
              unsigned char G[WIDTH][HEIGHT],
              unsigned char B[WIDTH][HEIGHT]);

void ModifyImage(unsigned char R[WIDTH][HEIGHT],
                 unsigned char G[WIDTH][HEIGHT],
                 unsigned char B[WIDTH][HEIGHT]);

/*** function definitions ***/

/* write the RGB image to a PPM file    */
/* (return 0 for success, >0 for error) */

int WriteImage(
	char Filename[SLEN],
	unsigned char R[WIDTH][HEIGHT],
	unsigned char G[WIDTH][HEIGHT],
	unsigned char B[WIDTH][HEIGHT])
{
    FILE *File;
    int  x, y;

    File = fopen(Filename, "w");
    if (!File)
    {	printf("\nCannot open file \"%s\" for writing!\n", Filename);
	return(1);
    }
    fprintf(File, "P6\n");
    fprintf(File, "%d %d\n", WIDTH, HEIGHT);
    fprintf(File, "255\n");
    for(y=0; y<HEIGHT; y++)
    {	for(x=0; x<WIDTH; x++)
	{   fputc(R[x][y], File);
	    fputc(G[x][y], File);
	    fputc(B[x][y], File);
	}
    }
    if (ferror(File))
    {	printf("\nFile error while writing to file!\n");
	return(2);
    }
    fclose(File);
    return(0);	/* success! */
} /* end of WriteImage */

/* read the RGB image from a PPM file   */
/* (return 0 for success, >0 for error) */

int ReadImage(
	char Filename[SLEN],
	unsigned char R[WIDTH][HEIGHT],
	unsigned char G[WIDTH][HEIGHT],
	unsigned char B[WIDTH][HEIGHT])
{
    FILE *File;
    char Type[SLEN];
    int  Width, Height, MaxValue;
    int  x, y;

    File = fopen(Filename, "r");
    if (!File)
    {	printf("\nCannot open file \"%s\" for reading!\n", Filename);
	return(1);
    }
    fscanf(File, "%79s", Type);
    if (Type[0] != 'P' || Type[1] != '6' || Type[2] != 0)
    {	printf("\nUnsupported file format!\n");
	return(2);
    }
    fscanf(File, "%d", &Width);
    if (Width != WIDTH)
    {	printf("\nUnsupported image width %d!\n", Width);
	return(3);
    }
    fscanf(File, "%d", &Height);
    if (Height != HEIGHT)
    {	printf("\nUnsupported image height %d!\n", Height);
	return(4);
    }
    fscanf(File, "%d", &MaxValue);
    if (MaxValue != 255)
    {	printf("\nUnsupported image maximum value %d!\n", MaxValue);
	return(5);
    }
    if ('\n' != fgetc(File))
    {	printf("\nCarriage return expected!\n");
	return(6);
    }
    for(y=0; y<HEIGHT; y++)
    {	for(x=0; x<WIDTH; x++)
	{   R[x][y] = fgetc(File);
	    G[x][y] = fgetc(File);
	    B[x][y] = fgetc(File);
	}
    }
    if (ferror(File))
    {	printf("\nFile error while reading from file!\n");
	return(7);
    }
    fclose(File);
    return(0);	/* success! */
} /* end of ReadImage */

/* modify the image...  ;-) */

void ModifyImage(unsigned char R[WIDTH][HEIGHT],
                 unsigned char G[WIDTH][HEIGHT],
                 unsigned char B[WIDTH][HEIGHT])
{   int  x, y;

    for(y=0; y<HEIGHT; y++)
    {   for(x=0; x<WIDTH; x++)
        {
            B[x][y] = (R[x][y] + G[x][y] + B[x][y]) / 5;
            R[x][y] = (unsigned char) (B[x][y]*1.6);
            G[x][y] = (unsigned char) (B[x][y]*1.6);
        }
    }

} /* end of ModifyImage */


/*** main program ***/

int main(void)
{
    /* image data */
    unsigned char R[WIDTH][HEIGHT];
    unsigned char G[WIDTH][HEIGHT];
    unsigned char B[WIDTH][HEIGHT];
    /* file name */
    char Filename[SLEN];

    printf("Enter input file name:  ");
    scanf("%79s", Filename);
    if (ReadImage(Filename, R,G,B) != 0)
    { exit(10); }

    /* modify the image */
    ModifyImage(R, G, B);

    printf("Enter output file name: ");
    scanf("%79s", Filename);
    if (WriteImage(Filename, R,G,B) != 0)
    { exit(10); }

    return 0;
} /* end of main */

/* EOF */
