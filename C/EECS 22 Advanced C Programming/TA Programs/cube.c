/* Calculate the volume of a cube
   Emad Arasteh
   October 4, 2018
 */

#include <stdio.h>

int main() {

  float length = 0, volume = 0;

  printf("Please enter the length of the cube:");
  scanf("%f", &length);

  volume = length * length * length;

  printf("The volume of cube is %f \n", volume);

  return 0;

}
