```c
int main(int argc, string argv[])
{
    string cipher_text = argv[1];
    // retrieves the salt
    char salt[100];
    strncpy(salt, argv[1], 2);
    salt[2] = 0;
    
    FILE *file;
    //hard coded, should change
    string words[100000];
    char word[60];
    int count = 0;
    int length = 0;
    
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
        // if (length < 12)
        // {
            word[length - 1] = '\0';   
            words[count] = strdup(word);
            // printf("storing %s\n", words[count]);
            count++;
        // }
    }
    //stop reading the file
  fclose(file);
  
//   printf("done with %i words\n", count);
   
//   printf("checking passwords");
   
// check each word in dictionary if it's the password
  for (int j = 0; j < count; j++)
  {
     if (CheckMatch(words[j], cipher_text, salt))
     {
        printf("%s\n", words[j]);
        break;
     }
  }

   return 0;
}
```