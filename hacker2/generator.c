#include <cs50.h>
#include <string.h>
#include <stdio.h>

int GenerateStringOfLength(int length);
int GenerateString(string pass, int start, int end, int index, int length);

int main(void)
{
    
    // for (int i = 0; i < length; i++) {
    GenerateStringOfLength(6);
    // }
    
    return 0;
}

int GenerateStringOfLength(int length)
{
    // create temporary string of given length
    char temp_string [length];
    GenerateString(temp_string, 97, 123, 0, length);
      printf("\n");
    return 0;
}

int GenerateString(string pass, int start, int end, int index, int length)
{
    //base case
    // if counter reaches 0
    if (index == length) 
    {
      // signal end of the string
      pass[index] = '\0';
      if (!strcmp("banana", pass))
      {
        printf("%s ", pass);
      }
      return 0;
    }
    //recursive case
    else 
    {
        for (int asci = start; (asci < end); asci++) 
        {
            pass[index] = (char) asci;
            GenerateString(pass, start, end, index + 1, length);
        }
    }
    return 0;
}
