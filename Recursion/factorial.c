#include <stdio.h>
#include <cs50.h>

int factorial(int n);

int main(void)
{
    int n = get_int("Factorial of ");
    printf("%i\n", factorial(n));
}

int factorial(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return factorial(n - 1) * n;
}