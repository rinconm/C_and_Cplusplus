/*********************************************************************/
/* Program: DIPs.h                                                   */
/* Purpose: Function declarations of the standard Digital Image      */
/*          Processing functions                                     */
/* Authors: Marcos Rincon, EECS 22 Teacher's Aid                     */
/*                                                                   */
/* Version History:                                                  */
/* 02/09/22 MR Modularized program to header file                    */
/* 01/24/22 TA Function declarations                                 */
/*********************************************************************/

#ifndef DIPS_H
#define DIPS_H


#include "Constants.h"

/* change color image to black & white */
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
		           int target_r,
		           int target_g,
		           int target_b,
		           int threshold,
		           int replace_r,
		           int replace_g,
		           int replace_b);

/* edge detection */
void Edge(unsigned char R[WIDTH][HEIGHT],
	  unsigned char G[WIDTH][HEIGHT],
	  unsigned char B[WIDTH][HEIGHT]);

/* Shuffle the image */
void Shuffle(unsigned char R[WIDTH][HEIGHT],
	     unsigned char G[WIDTH][HEIGHT],
	     unsigned char B[WIDTH][HEIGHT]);

/* mirror image vertically */
void VMirror(unsigned char R[WIDTH][HEIGHT],
	     unsigned char G[WIDTH][HEIGHT],
	     unsigned char B[WIDTH][HEIGHT]);

/* flip image vertically */
void VFlip(unsigned char R[WIDTH][HEIGHT],
	   unsigned char G[WIDTH][HEIGHT],
	   unsigned char B[WIDTH][HEIGHT]);

/* add border */
void AddBorder(unsigned char R[WIDTH][HEIGHT],
	       unsigned char G[WIDTH][HEIGHT],
	       unsigned char B[WIDTH][HEIGHT],
	                char color[SLEN],
	                 int border_width);


#endif /* DIPS_H */

/* EOF DIPs.h */
