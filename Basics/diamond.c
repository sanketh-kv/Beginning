#include<stdio.h>
#include<cs50.h>

int main (void)
{
    int h = 0;
    do
    {
    h = get_int("Height (Enter an odd number >= 3):  ");
    }
    while (h < 3 || h % 2 == 0);
    printf("\n");
    //Height (y-element)
    int hu = (h / 2) + 1;
    for (int i = 0; i < hu; i++)
    {
        //For Spaces (x-element)
        for (int j = 0; j < (hu - i - 1); j++)
        {
            printf(" ");
        }
        //For # (x-elelment)
        for (int x = 0; x < (i + 1); x++)
        {
            printf("#");
        }
        for (int y = 0; y < i; y++)
        {
            printf("#");
        }
        printf("\n");
    }
    int hl = h / 2;
    for (int i = 0; i < hl; i++)
    {
        for (int j = 0; j < (i + 1); j++)
        {
            printf(" ");
        }
        for (int x = 0; x < (hl - i); x++)
        {
            printf("#");
        }
        for (int y = 0; y < (hl - i - 1); y++)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");
}