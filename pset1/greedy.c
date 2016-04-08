#include <cs50.h>
#include <stdio.h>

int CountChange(int total);

float GetPositiveFloat(void);

int main(void) 
{
  printf("O hai! ");
  // get user input and convert to cents
  // NOTE: goes past the 2nd decimal place to properly round numbers
  int change = (GetPositiveFloat() * 1000) / 10;
  int result = CountChange(change);
  printf("%i\n", result);
}

// Counts the change and returns number of coins
//TODO: Refactor
int CountChange(int total)
{
  // initialize coin sum
  int coinSum = 0;
  
  // calculates number of coins
  do
  {
    // quarters
    if (total >= 25)
    { 
      // add no. of quarters that can be used to coinsum
      coinSum = coinSum + (total / 25);
      // set total to remainder
      total = total % 25;
    }
    // dimes
    else if (total >= 10)
    {
      coinSum = coinSum + (total / 10);
      total = total % 10; 
    }
    // nickels
    else if (total >= 5)
    {
      coinSum = coinSum + (total / 5);
      total = total % 5;
    }
    // pennies
    else
    {
      coinSum = coinSum + total;
      total = 0;
    }
  }
  while (total > 0);
  return coinSum;
}

float GetPositiveFloat(void)
{
  float n;
  do
  {
    printf("How much change is owed?\n");
    n = GetFloat();
  }
  while (n < 0);
  return n;
}
