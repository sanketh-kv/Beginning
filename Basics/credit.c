#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // User Card number input
    long n;
    int count;
    n = get_long("Number:  ");
    long m = n;
    count = 0;
    while (m > 0)
    {
        m = m / 10;
        count++;
    }

    long p = n;
    long nA = n;
    long nM = n;
    long nV = n;
    int a = 0;
    int b = 0;
    int c = 0;
    int g = 0;
    int h = 0;

    // Check sum
    for (int i = 0; i < count; i++)
    {
        int x = p % 10;
        p = p / 10;
        if (i % 2 == 0)
        {
            a = a + x;
        }
        else
        {
            c = 2 * x;
            if (c / 10 == 0)
            {
                b = b + c;
            }
            else
            {
                g = c % 10;
                h = c / 10;
                b = b + h + g;
            }
        }
    }
    //printf("a  %i, b  %i\n", a,b);
    // Card validation
    if ((a + b) % 10 == 0)
    {
        //American Express
        if (count == 15)
        {
            for (int r = 0; r < (count - 2); r++)
            {
                nA = nA / 10;
            }
            //Amex starting digits check
            if (nA == 34 || nA == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        //MasterCard & 16-digit Visa card
        else if (count == 16)
        {
            for (int s = 0; s < (count - 2); s++)
            {
                nM = nM / 10;
            }
            //Master starting digits check
            if (nM == 51 || nM == 52 || nM == 53 || nM == 54 || nM == 55)
            {
                printf("MASTERCARD\n");
            }
            //Visa (16 digit) starting digit check
            else if (nM / 10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        //13-digit Visa
        else if (count == 13)
        {
            for (int t = 0; t < (count - 1); t++)
            {
                nV = nV / 10;
            }
            //Visa (16 digit) starting digit check
            if (nV == 4)
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
    }
    else
    {
        printf("INVALID\n");
    }
}