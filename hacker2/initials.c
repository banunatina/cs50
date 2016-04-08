#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
  // gets user input
  string name = GetString();  

  for (int i = 0; i < strlen(name); i++) 
  {
      // checks if current letter is a space
      if (name[i] != 32)
      {
        // prints if first letter, or if a letter after a space
        if ((i == 0) || (name[i - 1] == 32 && name[i] != 32))
        {
          // checks if letter is lowercase
          if (name[i] > 96 && name[i] < 123)
          {
            // converts lowercase letter to uppercase letter using ASCII
            printf("%c", name[i] - 32);
          }
          // prints name[i] normally otherwise        
          else
          {
            printf("%c", name[i]);
          }
        }
      }
  }
  // prints newline
  printf("\n");

  return 0;
}
