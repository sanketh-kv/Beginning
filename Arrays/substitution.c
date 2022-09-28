#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char sub(string s, char c);

int main(int argc, string argv[])
{
    //Check for single command-line argument
    if (argc > 2 || argc < 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //Check for 26-character key input
    if (strlen(argv[1]) < 26 || strlen(argv[1]) > 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //Check for alphabetical input
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(argv[1][i]))
        {}
        else
        {
            printf("Only alphabetical key\n");
            return 1;
        }
    }

    //Check for unique characters
    for (int i = 0; i < 26; i++)
    {
        for (int j = (i + 1); j < 25; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must contain 26 unique alphabets\n");
                return 1;
            }
        }
    }

    //User plaintext input
    string plain = get_string("plaintext:  ");

    //Cipher conversion
    int len = strlen(plain);
    char cipher[len];

    for (int i = 0; i < len; i++)
    {
        cipher [i] = sub(argv[1], plain[i]);
    }
    printf("ciphertext: ");

    for (int c = 0; c < len; c++)
    {
        printf("%c", cipher[c]);
    }
    printf("\n");
}



char sub(string s, char c)
{
    if (isalpha(c))
    {
        //Lowercase case
        if (islower(c))
        {
            int x = c - 97;
            char g = s[x];
            //Case preservation
            if (islower(g))
            {
                return g;
            }
            else
            {
                char h = tolower(g);
                return h;
            }
        }
        //Uppercase case
        else
        {
            int x = c - 65;
            char g = s[x];
            //Case preservation
            if (isupper(g))
            {
                return g;
            }
            else
            {
                char h = toupper(g);
                return h;
            }
        }

    }
    else
    {
        return c;
    }
}