#include <cs50.h>
#include <stdio.h>

int GetPositiveInt(void);

int main(void)
{
  int mins = GetPositiveInt();
  // converts minutes to bottles 
  mins = (mins * 1.5 * 128) / 16;
  // prints the number of bottles
  printf("bottles: %i\n", mins);
}

// obtains a positive integer from the user
int GetPositiveInt(void)
{
  int n;
  // continues to prompt user if integer is negative
  do
  {
    printf("minutes: ");
    n = GetInt();
  }
  while (n < 1);

  return n;
}
