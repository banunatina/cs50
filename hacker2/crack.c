#define _XOPEN_SOURCE

#include <unistd.h>
#include <string.h>
#include <cs50.h>
#include <stdio.h>

char *strdup(const char *s);

int CheckMatch(string plain, string cipher, char salt[]);
int CheckDict(string cipher_text, string salt);
int GenerateStringOfLength(int length, string cipher_text, string salt);
int GenerateString(string pass, int start, int end, int index, int length, string cipher_text, string salt);

int main(int argc, string argv[])
{
    string cipher_text = argv[1];
    // retrieves the salt
    char salt[100];
    strncpy(salt, argv[1], 2);
    salt[2] = 0;
    
    // only runs if dictionary doesn't find it
    // generates possible password combinations
    if (CheckDict(cipher_text, salt))
    {
        int match = 1;
        printf("Not in dictionary. Generating...");
        // for lengths 2 to 8, generate strings
        for (int i = 1; (i < 8) && (match == 1); i++) 
        {
            match = GenerateStringOfLength(i + 1, cipher_text, salt);
        }

    }
   return 0;
}
 
// checks plaintext against cipher given with salt to determine if it's the password   
int CheckMatch(string plain, string cipher, char salt[])
{

    // compare returns 0 if equal
        // if (strcmp(crypt(plain, salt), cipher) == 0) {

    if (strcmp((crypt(plain, cipher)), cipher) == 0) {
        //if equal, match is truthy
      
      return 0;
    }
    else 
    {
        return 1;
    }
}

    
int GenerateStringOfLength(int length, string cipher_text, string salt)
{
    // create temporary string of given length
    char temp_string [length];
    printf(".");
    int match = 0;
    match = GenerateString(temp_string, 32, 127, 0, length, cipher_text, salt);
    return match;
}

int GenerateString(string pass, int start, int end, int index, int length, string cipher_text, string salt)
{
    int match = 1;
    //base case
    // if counter reaches 0
    if (index == length) 
    {
      // signal end of the string
      pass[index] = '\0';
          // if matches, print
        if (CheckMatch(pass, cipher_text, salt) == 0)
        {
            printf("Cracked! The password is: %s\n", pass);
            match = 0;
        }
        
        return match;
    }
    //recursive case
    else 
    {

        // for (int asci = start; (asci <= end) && (end - asci + 1 >= length - index); asci++) 
        for (int asci = start; asci < end && match == 1; asci++) 
        {
            pass[index] = (char) asci;
            match = GenerateString(pass, start, end, index + 1, length, cipher_text, salt);
        }
    }
    
    return match;
    
}


// reads dictionary and prints the password if it is in the dictionary
// TODO: refactor 
int CheckDict(string cipher_text, string salt)
{
    FILE *file;
    //hard coded, should change
    string words[100000];
    char word[60];
    int count = 0;
    int length = 0;
    string correct;
    int matched = 0;
    
    // read dictionary to check for words
    file = fopen("/usr/share/dict/words", "r");
    // if file doesn't exist, throw error
    if (file == NULL) 
    {
        printf("Error opening file!");
        return 1;
    }
    
    // storing words in array
    while ( fgets(word, 60, file) != NULL ) 
    {
        length = strlen(word);

            word[length - 1] = '\0';   
            words[count] = strdup(word);
            // printf("storing %s\n", words[count]);
            count++;
    }
    //stop reading the file
  fclose(file);
  
  int j = 0;
  
  // check each word in dictionary if it's the password
  while ((j < count) && (matched < 1))
  {
      // if found a match, prints it and toggles flag
      if (CheckMatch(words[j], cipher_text, salt) == 0)
      {
        correct = words[j];
        printf("Cracked! The password is: %s\n", correct);
        matched = 1;
      }
      j++;
  }
  
  // return values
  if (matched == 1)
  {
      return 0;
  }
  else 
  {
      return 1;
  }
  
}