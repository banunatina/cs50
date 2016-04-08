#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string GetValidString(void);

int main(int argc, string argv[])
{
  // throw an error if no arguments are passed to command line
  if (argc == 2)
  {
      // check if argument passed is a digit 
      if (isdigit(argv[1][0]))
      {
        // convert rot to integer
        int rot = atoi(argv[1]);
        // get user string input
        string input = GetValidString();
        // rotate by rot 
        for (int i = 0, n = strlen(input); i < n; i++)
        {
           char letter_to_print = input[i];
           int letter;
           int offset;
           int rot_letter;
           // check if is in alphabet
           if (isalpha(input[i]))
           {
             // store typecast letter
             letter = (int) input[i]; 
             // if upper, wrap around using 90 as upper limit and 65 as lower limit
             if ((isupper(input[i])))
             {
               // calculate offset
                offset = (letter - 65 + rot) % 26;
                rot_letter = offset + 65;
                letter_to_print = (char) rot_letter;   
             }
              // else wrap around using 122 and 97 
             else if (islower(input[i]))
             {
                // calculate offset
                offset = (letter - 97 + rot) % 26;
                rot_letter = offset + 97;
                letter_to_print = (char) rot_letter;
             }
            }
            // print letter
            printf("%c", letter_to_print);
         }
          
           // prints newline at end of return string and returns 0
           printf("\n");
           return 0;
      }
   }
   else
   {
      // if anything goes wrong return error
      printf("Something went wrong.\n");
      return 1;
   }
}

string GetValidString(void)
{
  string str = GetString();

  while (strlen(str) < 1) 
  {
    printf("Please insert a valid string:\n");
    str = GetString();
  }

  return str;
}   
