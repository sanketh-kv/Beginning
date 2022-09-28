#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);
void cl_index(int let, int wor, int sen);


int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    cl_index(letters, words, sentences);
}

//Counting letters
int count_letters(string s)
{
    int n = strlen(s);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        //Alphabet check
        if (isalpha(s [i]))
        {
            count++;
        }
    }
    return count;
}

//Counting words
int count_words(string s)
{
    int n = strlen(s);
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        //Space check
        if (isspace(s [i]))
        {
            count++;
        }
    }
    return count;
}

//Counting sentences
int count_sentences(string s)
{
    int n = strlen(s);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        //End punctuation check
        if (s [i] == 46 || s [i] == 63 || s [i] == 33)
        {
            count++;
        }
    }
    return count;
}

//Coleman-Liau index
void cl_index(int let, int wor, int sen)
{
    float L = 100.0 * let / wor;
    float S = 100.0 * sen / wor;
    //Index formula
    float x = (0.0588 * L) - (0.296 * S) - 15.8;
    //Before 1 exception
    if (x < 1)
    {
        printf("Before Grade 1\n");
    }
    //16+ exception
    else if (x >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(x));
    }
}