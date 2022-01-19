/* Program: weekday.c                                                    */
/* Purpose: Prompts the user for the calendar date and uses the input to */
/*          calculate the weekday using Zeller's congruence algorithm.   */ 
/* Author : Marcos Rincon                                                */
/*                                                                       */
/* Version History:                                                      */
/* 01/11/22 MR  initial version                                          */

/* preprocessor directives */
#include <stdio.h>
#include <string.h>
#define LEN 10	            /* string length 10 */

/* main function */
int main(void)
{
    /* variable definitions */
    int day;
    int month;
    int year;
    int numWeek;
    char strWeek[LEN];

    /* input section */
    /* Prompt the user to enter a valid calendar date. */
    printf("A valid calendar date is in the following format:\n");
    printf("\tDay = 12\n");
    printf("\tMonth = 1\n");
    printf("\tYear  = 2022\n\n");
    printf("Please enter a calendar date:\n");
    printf("Day = ");
    scanf("%d", &day);
    printf("Month = ");
    scanf("%d", &month);
    printf("Year = ");
    scanf("%d", &year);

    /* data preprocessing section */
    /* Deal with the exception for the months of January and February. */
    if (month < 3)
    {   month += 12;
        year -= 1;
    } /* fi */

    /* computate section */
    /* Use Zeller's congruence algorithm. */
    numWeek = (day + ((month + 1) * 13) / 5 + (year % 100) + ((year % 100)/4) + ((year / 100)/4) - 2 * (year / 100)) % 7;
    /* Generate weekday string. */
    switch(numWeek)
    {   case 0 : 
        {   strcpy(strWeek, "Saturday");
            break;
         }
        case 1 : 
        {   strcpy(strWeek, "Sunday");
            break;
         }
        case 2 : 
        {   strcpy(strWeek, "Monday");
            break;
         }
        case 3 : 
        {   strcpy(strWeek, "Tuesday");
            break;
         }
        case 4 : 
        {   strcpy(strWeek, "Wednesday");
            break;
         }
        case 5 : 
        {   strcpy(strWeek, "Thursday");
            break;
         }
        case 6 : 
        {   strcpy(strWeek, "Friday");
            break;
         }
    } /* hctiws */
    
    /* data postprocessing section */
    /* Readjust exception for the months of January and February. */
    if (month > 12)
    {   month -= 12;
        year += 1;
    } /* fi */

    /* output section */
    /* Print a numerical identifier (0-6) to represent the computed */
    /* weekday, and also print the result as a text string. */
    printf("For the calendar date %d/%d/%d, the day of the week is %d.\n", month, day, year, numWeek);
    printf("This is a %s.\n", strWeek);

    /* exit */
    return 0;
} /* end of main */

/* EOF */