/*********************************************************************/
/* Program: FileIO.h                                                 */
/* Purpose: Function declarations of the Input/Output functions      */
/* Authors: Marcos Rincon, EECS 22 Teacher's Aid                     */
/*                                                                   */
/* Version History:                                                  */
/* 02/09/22 MR Modularized program to header file                    */
/* 01/24/22 TA Function declarations                                 */
/*********************************************************************/

#ifndef FILE_IO_H
#define FILE_IO_H


#include "Constants.h"

/* read image from a file */
int LoadImage(const          char fname[SLEN],
	            unsigned char R[WIDTH][HEIGHT],
	            unsigned char G[WIDTH][HEIGHT],
	            unsigned char B[WIDTH][HEIGHT]);

/* save a processed image */
int SaveImage(const          char fname[SLEN],
	            unsigned char R[WIDTH][HEIGHT],
	            unsigned char G[WIDTH][HEIGHT],
	            unsigned char B[WIDTH][HEIGHT]);


#endif /* FILE_IO_H */

/* EOF FileIO.h */
