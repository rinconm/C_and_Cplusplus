/* Define a struct to describe a point and a triangle in the 2D plane,
   and implement methods to display and find perimeter
   of an arbitrary triangle
   Optional exercise: write a function to implement an area of a triangle
   author: Emad Arasteh (emalekza@uci.edu)
   11/21/19 EA initial version
   02/04/22 EA minor refactoring
*/
#include <stdio.h>
#include <math.h>

typedef struct
{
  int x;
  int y;
} point_t;

typedef enum {scalene, equilateral, isosceles, right} triangle_type;

typedef struct
{
  point_t       v[3]; /* vertices */
  triangle_type type;
} triangle_t;

void display(triangle_t triangle)
{
  int i;
  for (i = 0; i< 3; i++)
  {
      printf("(X,Y) coordinates for vertex %0d of a triangle: (%0d, %0d)\n",
	     i, triangle.v[i].x, triangle.v[i].y);
  }

  printf("Type of a triangle is ");
  switch(triangle.type)
  {
    case scalene:
      printf("scalene.\n");
      break;
    case equilateral:
      printf("equilateral.\n");
      break;
    case isosceles:
      printf("isosceles.\n");
      break;
    case right:
      printf("right.\n");
      break;
    default:
      break;
  }
}

double perimeter(triangle_t t)
{
  double side_a, side_b, side_c, perimeter = 0;
  /* compute the Euclidean distance between triangle's vertices */
  side_a = sqrt(pow(t.v[0].x - t.v[1].x, 2) + pow(t.v[0].y - t.v[1].y, 2));
  side_b = sqrt(pow(t.v[1].x - t.v[2].x, 2) + pow(t.v[1].y - t.v[2].y, 2));
  side_c = sqrt(pow(t.v[2].x - t.v[0].x, 2) + pow(t.v[2].y - t.v[0].y, 2));
  perimeter = side_a + side_b + side_c;
  return perimeter;
}

int main()
{
  triangle_t triangle = { { {0, 0}, {6, 0}, {6, 8} } , right };
  display(triangle);
  printf("Perimeter of the triangle is %f \n", perimeter(triangle));
  return 0;
}
