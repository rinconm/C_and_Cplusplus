/* Add two timestamps (t1 + t2) and print the result
   Emad Arasteh
   October 4, 2018
 */

#include <stdio.h>

int main() {

  int s1  = 0, m1 = 0, h1 = 0, t1 = 0; /* timestamp1 */
  int s2  = 0, m2 = 0, h2 = 0, t2 = 0; /* timestamp2 */ 
  int sum = 0;                         /* sum of timestamps in seconds */
  int s = 0, m = 0, h = 0;             /* timestamp in sec, min, hour  */

  printf("Please enter the first timestamp\n");
  printf("s1: ");
  scanf("%d", &s1);
  printf("m1: ");
  scanf("%d", &m1);
  printf("h1: ");
  scanf("%d", &h1);

  printf("Please enter the second timestamp\n");
  printf("s2: ");
  scanf("%d", &s2);
  printf("m2: ");
  scanf("%d", &m2);
  printf("h2: ");
  scanf("%d", &h2);

  t1 = s1 + m1*60 + h1*60*60;
  t2 = s2 + m2*60 + h2*60*60;

  sum = t1 + t2;

  s   = sum % 60;
  sum = sum / 60;
  m   = sum % 60;
  h   = sum / 60;

  printf("Sum of the two timestamps is %d hours %d minutes and %d seconds. \n", h, m, s);

  return 0;
}
