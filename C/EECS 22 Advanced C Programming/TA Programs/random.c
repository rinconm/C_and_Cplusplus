/* Generate a random number in range from 0 to 1999
   Emad Arasteh
   October 17, 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int unsigned rand_x;

  srand(time(NULL));

  rand_x = rand() % 2000;

  printf("The generated random number is %u \n", rand_x);

  return 0;
}
