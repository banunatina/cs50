#include <cs50.h>
#include <stdio.h>

int GetValidInt(void);

int main(void)
{
  // get the user's input
  printf("Height: ");
  int height = GetValidInt();
  
  // render pyramid if input is more than 0
  if (height > 0) 
  {
    //initialize spaces and pounds for rendering
    int spaces = height - 1;
    int pounds = 1;
    
    do
    {
      //draw spaces for the current row
      for (int i = 0; i < spaces; i++)
      {
        printf(" ");
      }
      //draw pounds for the current row
      for (int i = 0; i <= pounds; i++)
      {
        printf("#");
      }
      // updates number of pounds and spaces for the next row
      pounds++;
      spaces--;
      // inserts newline to go to next row
      printf("\n");
    }
    // while there are still rows left
    while (pounds <= height || spaces > 0);
  }
  
  return 0;
}

// function that gets user input and only accepts valid integers
int GetValidInt(void)
{
  // Get the integer initially
  int n = GetInt();
  
  // while not valid, keep prompting
  while ((n < 0) || (n > 23))
  {
    printf("Retry: ");
    n = GetInt();
  }
  // return the integer
  return n;
}
