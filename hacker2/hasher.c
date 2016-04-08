#define _XOPEN_SOURCE

#include <unistd.h>
#include <string.h>
#include <cs50.h>
#include <stdio.h>

// char *strdup(const char *s);

// int CheckMatch(string plain, string cipher, char salt[]);

int main(int argc, string argv[])
{
    string plain_text = argv[1];
    string salt = "HA";
    // string correct;
    // retrieves the salt
    // char salt[100];
    // strncpy(salt, argv[1], 2);
    // salt[2] = 0;
    
    string crypted = crypt(plain_text, salt);
    printf("%s\n", crypted);
    return 0;
  
}

// int CheckMatch(string plain, string cipher, char salt[])
// {
//     string result;
//     string test;
//     int match = 1;
    
//     if (strcmp(crypt(plain, salt), cipher)) {
//       match = 0;
//     }
//     // result = crypt(plain, cipher);
//     // match = strcmp(result, cipher) == 0;
//     return match ? 0 : 1;
//     // return 1;
// }
