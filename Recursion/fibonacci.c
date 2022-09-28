#include <stdio.h>
#include <cs50.h>

int fibonacci(int n, int arr[]);

int main (void)
{
    int n = get_int("Enter n: ");
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        //printf("%i ", fibonacci(i));
        arr[i] = fibonacci(i, arr);
    }

    printf("\n");
}

int fibonacci(int n, int arr[])
{
    if(n == 0 || n == 1)
    return n;
    else
    return arr[n - 1] + arr[n - 2];
}