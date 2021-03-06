#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TAG_datastruct{
   char *string;
   int checksum;
}datastruct;

datastruct* get_input(void);
void print_message(datastruct *);

int main(void)
{
   int counter;
   int maxval = 0;
   datastruct * svalues[200];

   for(counter = 0; counter < 200; counter++){
      svalues[counter] = get_input();
      if(!svalues[counter]){
         break;
      }
      maxval = counter;
   }

   print_message(svalues[maxval/2]);
   return 0;
}

datastruct *get_input()
{
   char input[80];
   datastruct * instruct;
   int counter;
   printf("Enter a string, or leave blank when done: ");
   fgets(input, 79, stdin);
   input[strlen(input) - 1] = '\0';
   if(strlen(input) == 0){
      return NULL;
   }
   instruct = malloc(sizeof(datastruct));
   instruct->string = strdup(input);
   instruct->checksum = 0;
   for(counter = 0; counter < strlen(instruct->string); counter++){
      instruct->checksum += instruct->string[counter];
   }
   return instruct;
}

void print_message(datastruct * todisp)
{
   printf("This structure has a checksum of %d. It's string is: \n",
	 todisp->checksum);
   puts(todisp->string);
}
