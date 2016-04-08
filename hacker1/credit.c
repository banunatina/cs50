#include <cs50.h>
#include <stdio.h>
#include <math.h>

int IsAmex(long long);
int IsMasterCard(long long);
int IsVisa(long long);
int CheckSum(long long);

int main(void)
{
  // get input from user
  printf("Number: ");
  long long cardNum = GetLongLong();
  // checks if card is Amex
  if (CheckSum(cardNum))
  {
    if (IsAmex(cardNum))
    {
      printf("AMEX\n");
    } 
    // checks if card is Mastercard
    else if (IsMasterCard(cardNum))
    {
      printf("MASTERCARD\n");
    }
    // checks if card isVisa
    else if (IsVisa(cardNum))
    {
      printf("VISA\n");
    }
    else
    {
      printf("INVALID\n");
    }
  }
  else
  {
    printf("INVALID\n");
  }

  return 0;
}

// checks if card is Amex according to first two numbers
int IsAmex(long long cardNum)
{
   if ((cardNum >= (34 * pow(10, 13))) && (cardNum < (35 * pow(10, 13))))
   {
  // return 1 if valid
     return 1;
   }

   if ((cardNum >= (37 * pow(10, 13))) && (cardNum < (38 * pow(10, 13))))
   {
     // return 1 if valid
     return 1;
   }
 
   return 0;
}

// checks if card is Mastercard according to first two numbers
int IsMasterCard(long long cardNum)
{
   if ((cardNum >= (51 * pow(10, 14))) && (cardNum < (56 * pow(10, 14))))
   {
    // return 1 if valid
     return 1;    
   }

   return 0;
}

// checks if card is Visa according to first number
int IsVisa(long long cardNum)
{
  if ((cardNum >= (4 * pow(10, 12))) && (cardNum < (5 * pow(10, 12))))
  {
  // return 1 if valid
    return 1;
  }

  if ((cardNum >= (4 * pow(10, 15))) && (cardNum < (5 * pow(10, 15))))
  {
  // return 1 if valid
    return 1;
  }
  // returns false if invalid
  return 0;
}

int CheckSum(long long cardNum)
{
  //initialize checkSum variables
  int multiSum = 0;
  int normalSum = 0;
  // make copy of cardNum to preserve cardNum
  long long cardNumCopy = cardNum;

  // iterates over cardNumCopy until the last digit
  for (int i = 0; cardNumCopy < 10; i++)
  {
    // if 'odd' number
    if ((i > 0) && (i % 2 != 0))
    {
      // remove last number from cardNumCopy
      cardNumCopy = (cardNum / pow(10, i));
      // add current last number to multiSum
      multiSum += (cardNumCopy % 10) * 2;
    } else
    // if 'even' number
    {
      // remove last number from cardNumCopy
      cardNumCopy = (cardNum / pow(10, i));
      // add current last number to normalSum
      normalSum += cardNumCopy % 10;
    }
  }
  // if normalSum + multiSum % 10 == 0
  if ((normalSum + multiSum) % 10 == 0)
  {
    // return 1
     return 1;
  }
  else
  {
  // else return 0
    return 0;
  }
}
