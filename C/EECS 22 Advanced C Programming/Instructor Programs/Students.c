/* Students.c: simple array of student records	*/
/* author: Rainer Doemer			*/
/* modifications:				*/
/* 08/28/13 RD initial version			*/

#include <stdio.h>
#include <stdlib.h>

/* constants */

#define SLEN 40
#define MAX 100

/* data structures */

struct Student
{  int  ID;
   char Name[SLEN];
   int  Score;
};
typedef struct Student STUDENT;

STUDENT Record[MAX];
int N = 0;

/* function declarations */

STUDENT EnterStudent(void);
void PrintStudent(STUDENT s);
char LetterGrade(int Score);
void InsertStudent(STUDENT s);

/* function definitions */

STUDENT EnterStudent(void)
{
    STUDENT s;

    printf("Enter student ID:    ");
    scanf("%d", &s.ID);
    printf("Enter student name:  ");
    scanf("%39s", &s.Name[0]);
    printf("Enter student score: ");
    scanf("%d", &s.Score);
    return s;
}

void PrintStudent(STUDENT s)
{
    printf("ID %3d: %-39s, Score %3d%% = %c\n",
		s.ID, s.Name, s.Score, LetterGrade(s.Score));
}

char LetterGrade(int Score)
{
    switch(Score/10)
    {   case 10:
	case  9: return 'A';
	case  8: return 'B';
	case  7: return 'C';
	case  6: return 'D';
	case  5:
	case  4:
	case  3:
	case  2:
	case  1:
	case  0: return 'F';
	default: break;
    } /* hctiws */
    return '-';
}

void InsertStudent(STUDENT s)
{
    int i, j;

    for(i=0; i<N; i++)
    {
	if (s.ID < Record[i].ID)
	{ break;
	}
    }
    for(j=N; j>i; j--)
    {
	Record[j] = Record[j-1];
    }
    Record[i] = s;
    N++;
}

int main(void)
{
    int Choice, i;

    while(1)
    {   printf("Student records: %d\n", N);
	printf("1. Enter new student\n");
	printf("2. Print student table\n");
	printf("3. Quit\n");
	printf("Choice: ");
	scanf("%d", &Choice);
	switch(Choice)
	{ case 1:
	    {	if (N < MAX)
		{   InsertStudent(EnterStudent());
		}
		break;
	    }
	  case 2:
	    {   for(i=0; i<N; i++)
		{ PrintStudent(Record[i]);
		}
		break;
	    }
	  case 3:
	    {   exit(0);
	    }
	  default:
	    {   break;
	    }
	} /* hctiws */
    } /* elihw */
    return 0;
} /* end of main */

/* EOF */
