#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char rotate(int n, char c);

int main(int argc, string argv[])
{
    //Check for single command-line argument
    if (argc > 2 || argc < 2)
    {
        printf("Invalid input\n");
        return 1;
    }

    //Check for numeric argument
    int n = strlen(argv [1]);
    for (int i = 0; i < n; i++)
    {
        if (isdigit(argv [1][i]))
        {}
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //PlainText input
    string s = get_string("plaintext:  ");
    //Type conversion of key
    int key = atoi(argv[1]);
    int len = strlen(s);
    char cipher[len];

    //Cipher conversion
    for (int i = 0; i < len; i++)
    {
        cipher [i] = rotate(key, s [i]);
    }
    //Cipher print
    printf("ciphertext: %s\n", cipher);
}




char rotate(int n, char c)
{
    //Alphabet check
    if (isalpha(c))
    {
        //Lower case letters to cipher conversion
        if (islower(c))
        {
            int e = c + n;
            if (e < 123)
            {
                char cipher = e;
                return cipher;
            }
            else
            {
                do
                {
                    e = e - 26;
                }
                while (e > 122);
                char cipher = e;
                return cipher;
            }
        }
        //Upper case letters to cipher conversion
        else
        {
            int e = n + c;
            if (e < 91)
            {
                char cipher = e;
                return cipher;
            }
            else
            {
                do
                {
                    e = e - 26;
                }
                while (e > 90);
                char cipher = e;
                return cipher;
            }
        }
    }
    //Non-alphabet character return
    else
    {
        return c;
    }
}