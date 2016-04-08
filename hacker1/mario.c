#include <cs50.h>
#include <stdio.h>

int GetPositiveInt(void);

int main(void)
{
  // get the user's input
  printf("Height: ");
  int height = GetPositiveInt(); 

  if (height > 0)
  {
    int spaces = height - 1;
    int pounds = 1;

    do
    {
      for (int i = 0; i < spaces; i++)
      {
        printf(" ");
      }
      for (int i = 0; i < pounds; i++)
      {
        printf("#");
      }
      printf("  ");
      for (int i = 0; i < pounds; i++)
      {
        printf("#");
      }
      pounds++;
      spaces--;
      printf("\n");
    }
    while (pounds <= height || spaces > 0);
  }
  return 0;
}

int GetPositiveInt(void)
{
  int n = GetInt();
  while ((n < 0) || (n > 23))
  {
    printf("Retry: ");
    n = GetInt();
  }
  return n;
}
