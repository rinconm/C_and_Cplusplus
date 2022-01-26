/* A tiny calculator for integer opeations
   Emad Arasteh
   November 5, 2020
*/

#include <stdio.h>
#include <stdlib.h>

/* global variables to store two operands */
int x, y;

/* function declarations */
void printMenu(void);
void getInput(void);
void displayResult(int result);
int add(void);
int sub(void);
int mul(void);
int div(void);

/* function definitions */
void printMenu()
{
  printf("Operation 1: add \n");
  printf("Operation 2: sub \n");
  printf("Operation 3: mul \n");
  printf("Operation 4: div \n");
  printf("Press 0 to exit \n");
  printf("Please enter the operation number: ");
}

void displayResult(int r)
{
  printf("The result is %d \n", r);
  printf("********************************\n");
}

void getInput()
{
  printf("Please enter the first operand: ");
  scanf("%d", &x);
  printf("Please enter the second operand: ");
  scanf("%d", &y);
}

int add(void)
{
  return x+y;
}

int sub(void)
{
  return x-y;
}

int mul(void)
{
  return x*y;
}

int div(void)
{
  if (y == 0)
  {
    printf("Division by zero! Invalid!\n");
    exit(4);
  }
  return x/y;
}

int main()
{
  int choice = 0;
  int result;

  do
  {
    printMenu();
    scanf("%d", &choice);

    switch(choice)
    {
      case 1:
	getInput();
	result  = add();
	displayResult(result);
	break;
      case 2:
	getInput();
	result = sub();
	displayResult(result);
	break;
      case 3:
	getInput();
	result = mul();
	displayResult(result);
	break;
      case 4:
	getInput();
	result = div();
	displayResult(result);
	break;
      default :
	printf("**************************************\n");
	printf("Please enter a valid operation number!\n");
	printf("**************************************\n");
	break;
      case 0:
	break;
    }

  } while (choice != 0);

  return 0;
}
