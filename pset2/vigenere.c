#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string GetValidString(void);
int RotateLetter(char input_letter, char current_key);
int HasNoNumbers(string input);

int main(int argc, string argv[])
{
  // checks that the key is valid (no numbers) and that 1 argument was passed
  if ((argc == 2) && (!HasNoNumbers(argv[1])))
  {
    // stores the key
    string key = argv[1];
    // gets user string input
    string input = GetValidString();
    // initializes key_index for iterating over keys
    int key_index = 0;
    // flag that checks if key needs to be incremented
    int incr_flag;
    
    // iterate over each letter in input
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        // reinitializes key_index to 0 if needed
      if (key_index > strlen(key) - 1) 
      {
          key_index = 0;
      }
      
      // calls RotateLetter with current letter of input and current key
      // also stores the flag for incrementation of key_index if error is returned
      incr_flag = !RotateLetter(input[i], key[key_index]);
      
      // increment key index if needed
      if (incr_flag)
      {
          key_index++;
      }
    }
       // prints newline at end of return string and returns 0
       printf("\n");
       return 0;
  }
    // if anything goes wrong return error
    printf("Something went wrong.\n");
    return 1;
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

// rotates letter given with key letter given
int RotateLetter(char input_letter, char current_key)
{
   char letter_to_print = input_letter;
   int rot;
   int letter;
   int offset;
   int rot_letter;
   
   // convert key if need be
   if (isupper(current_key))
   {
       rot = (int) (tolower(current_key)) - 97;
   }
   else 
   {
       rot = (int) current_key - 97;
   }
   // convert only if input_letter is a letter
   if (isalpha(input_letter))
   {
     // store typecast letter
     letter = (int) input_letter; 
     // if upper, wrap around using 90 as upper limit and 65 as lower limit
     if ((isupper(input_letter)))
     {
       // calculate offset
        offset = (letter - 65 + rot) % 26;
        rot_letter = offset + 65;
        letter_to_print = (char) rot_letter;   
     }
      // else wrap around using 122 and 97 
     else if (islower(input_letter))
     {
        // calculate offset
        offset = (letter - 97 + rot) % 26;
        rot_letter = offset + 97;
        letter_to_print = (char) rot_letter;
     }
        // print letter
        printf("%c", letter_to_print);
        return 0;
    } 
    else
    {
      printf("%c", letter_to_print);
      return 1;
    }
}

// returns 1 if there are non-letters in the string
int HasNoNumbers(string input)
{
   for (int i = 0, n = strlen(input); i < n; i++)
   {
      if (isdigit(input[i])) 
      {
        return 1;    
      }
   }
   
   return 0;
}
