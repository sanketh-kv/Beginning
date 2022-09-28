#include <stdio.h>
#include <cs50.h>

int collatz(int n);

int main (void)
{
    int n = get_int("Number: ");
    printf("%i\n", collatz(n));
    return 0;
}

int collatz(int n)
{
    if(n == 1)
    {
        return 0;
    }
    else if(n % 2 == 0)
    {
        n = n / 2;
        return 1 + collatz(n);
    }
    else
    {
        n = 3*n + 1;
        return 1 + collatz(n);
    }
}