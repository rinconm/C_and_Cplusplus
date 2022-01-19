/*********************************************************/
/* FileIO.c: program file for I/O module                 */
/*********************************************************/

#include <stdio.h>
#include "FileIO.h"

/*** function definitions ***/

int ReadImage(char Filename[SLEN],
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

int WriteImage(char Filename[SLEN],
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

/* EOF FileIO.c */
