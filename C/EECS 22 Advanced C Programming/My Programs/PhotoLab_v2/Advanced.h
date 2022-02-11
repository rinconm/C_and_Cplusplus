/*********************************************************************/
/* Program: Advanced.h                                               */
/* Purpose: Function declarations of the Advanced Digital Image      */
/*          Processing functions                                     */
/* Authors: Marcos Rincon, Rainer Doemer                             */
/*                                                                   */
/* Version History:                                                  */
/* 02/09/22 MR Modularized program to header file                    */
/* 01/24/22 RD Function declarations                                 */
/*********************************************************************/

#ifndef ADVANCED_H
#define ADVANCED_H


#include "Constants.h"

/* add noise to an image */
void Noise(          int percentage,
	   unsigned char R[WIDTH][HEIGHT],
	   unsigned char G[WIDTH][HEIGHT],
	   unsigned char B[WIDTH][HEIGHT]);

/* sharpen the image */
void Sharpen(unsigned char R[WIDTH][HEIGHT],
	     unsigned char G[WIDTH][HEIGHT],
	     unsigned char B[WIDTH][HEIGHT]);

/* posterize the image */
void Posterize(unsigned char R[WIDTH][HEIGHT],
	       unsigned char G[WIDTH][HEIGHT],
	       unsigned char B[WIDTH][HEIGHT],
	       unsigned  int rbits,
	       unsigned  int gbits,
	       unsigned  int bbits);

/* motion blur */
void MotionBlur(          int BlurAmount,
		unsigned char R[WIDTH][HEIGHT],
		unsigned char G[WIDTH][HEIGHT],
		unsigned char B[WIDTH][HEIGHT]);



#endif /* ADVANCED_H */

/* EOF Advanced.h */
