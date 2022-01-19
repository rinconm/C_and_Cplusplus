// Program: hello-buddy-login-v2.c
// Purpose: User verification (login) menu with
//          sign up functionality 
// 
// Version History:
//  <11-30-21>	Marcos Rincon	init version
#include <stdio.h>
#include <string.h>
#define MAX_CHAR 25
#define MAX_USERS 10
#define MAX_ATTEMPTS 3

// Function Declarations
int puts(const char *str);      // Display strings up to null char
size_t strlen(const char *str); // Counts number of chars
int strcmp(const char *str1, const char *str2);
char *strcpy(char *dest, const char *src);
// main function - prints a hello message
int main(void)
{
   char mode = '0';
   int usernum = MAX_USERS+1;// Initialize to impossible user number
   char echo[MAX_CHAR];      // To store user input
   int len;                  // Number of input characters
   int i;	             // For loop variables
   int ret;                  // Function return status variable
   int attempts;             // Number of failed attempts
// Stored usernames along with encrypted passwords
   char users[MAX_USERS][MAX_CHAR] = 
   {"panteater", "qv", "marcos"};
   char pass[MAX_USERS][MAX_CHAR] =
   {"tixiv", "lippsxlivi%", "xli{m~evh"};
// {"peter", "hellothere!", "thewizard"};
// Display users and passwords
//   for (i=0; i<MAX_USERS; i++){
//   puts(users[i]);   
//   }
//   for (i=0; i<MAX_USERS; i++){
//   puts(pass[i]);
//   }
   while (1){               // Forever Loop to return to Start Menu unless break
      if (mode == '0'){     // Start-Menu Mode
         attempts = 0;      // Initialize failed attempts
         // Prompt for mode and store into feedback variable
         printf("\n---------------Start Menu---------------\n");
         printf("Enter '1' to login or '2' to sign up: ");
         scanf("%s", echo);
         // Count input characters and assign mode
         len = strlen(echo);
         mode = echo[0];
         }
      // Login Mode
      else if (mode == '1' && len == 1){
         while (attempts<MAX_ATTEMPTS) {
            printf("\n-----Login Menu-----\n");
            printf("Enter username: ");
            scanf("%s", echo);
            // Determines if input matches username database up to a maximum
            // number of attempts
            for (i=0; i<MAX_USERS; i++){
               ret = strcmp(echo, users[i]);
               if (ret == 0){
                  usernum = i;
                  break;
               }
            }
            if (ret == 0)
               break;
            else{
               printf("That username doesn't exist.\n");
               attempts +=1;
            }
         }
         if (usernum < MAX_USERS){          // Ask for password and compare
            attempts = 0;
            len = strlen(pass[usernum]);
            for (i=0; i<len; i++)
               pass[usernum][i] -= 4; 
            while (attempts<MAX_ATTEMPTS){
               printf("Enter password: ");
               scanf("%s", echo);
               ret = strcmp(echo,pass[usernum]);
               if (ret == 0)
                  break;
               else {
                  printf("That password does not match.\n");
                  attempts += 1;
               }
            }
            if (ret == 0){
               printf("Hello %s.\n", users[usernum]);
               printf("You have successfully logged in.\n");
               break;
            }
         }
         // Prompts maximum attempts and return to start menu
         printf("Maximum of %d attempts exceeded.\n", MAX_ATTEMPTS);
         printf("Returning to start menu\n");
         mode = 0;
      }
      // Signup mode
      else if (mode == '2' && len == 1){
         while(1){                        // Forever loop to try signup until break
            printf("\n-----Signup Menu-----\n");
            printf("Enter '0' to return to Start Menu.\n");
            printf("Username and password must start with a letter and max 25 characters.\n");
            printf("Enter desired username: ");
            scanf("%s", echo);
            len = strlen(echo);
            if (echo[0] == '0' && len == 1){
               printf("Returning to start menu...\n");
               mode = '0';
               break;
            }
            if (len > MAX_CHAR){
               printf("Username must be less than 25 characters.\n");
               continue;
            }
            if (echo[0] < 'A' || echo[0] > 'z') {
               printf("The first character is not a letter.\n");
               continue;
            }
            else if (echo[0] > 'Z' && echo[0] < 'a'){
               printf("The first character is not a letter.\n");
               continue;
            }
            // Determines if input username is already used and if not,
            // stores the username to the lowest empty username array
            for (i=0; i<MAX_USERS; i++){
               ret = strcmp(echo,users[i]); 
               len = strlen(users[i]);
               if (ret == 0){
                  printf("That username is already in use.\n");
                  break;
               }
               if (len == 0){
                  usernum = i;
                  strcpy(users[usernum], echo);
                  break;
               }
            }
            if (ret != 0){
               printf("Enter '0' to return to Start Menu.\n");
               printf("Enter desired password: ");
               scanf("%s", echo);
               len = strlen(echo);
               if (echo[0] == '0' && len == 1){
                  printf("Returning to start menu...\n");
                  mode = '0';
                  break;
               }
               if (len > MAX_CHAR){
                  printf("Password must be less than 25 characters.\n");
                  continue;
               }
               if (echo[0] < 'A' || echo[0] > 'z'){
                  printf("The first character is not a letter.\n");
                  continue;
               }
               else if (echo[0] > 'Z' && echo[0] <'a'){
                  printf("The first character is not a leeter.\n");
                  continue;
               }
              // If password acceptable, store and encrypt
              strcpy(pass[usernum], echo);
              for (i=0; i<len; i++)
                 pass[usernum][i] += 4;
              // Return to start menu
              mode = '0';
              break;
           }
           else
               printf("Please try again.\n");
         }
      }
      else {
         if (len > 25){
            printf("The character limit is 25.\n");
	    printf("You entered %d characters.\n", len);
            printf("Exiting program now...\n");
            return 0;
         }
         printf("Please try again.\n");
         mode = '0';
         continue;
      }
   }
   return 0;
}

/* EOF */

