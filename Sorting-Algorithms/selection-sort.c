#include <stdio.h>

void sort(int x[], int n);
void print_arr(int x[], int n);

int main (void)
{
    int x[] = {1, 3, 1};
    int n = sizeof(x) / 4;
    printf("Before sorting: ");
    print_arr(x, n);
    sort(x, n);
    printf("After  sorting: ");
    print_arr(x, n);
    return 0;
}



void sort(int x[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int max = i;
        for(int j = i + 1; j < n; j++)
        {
            if(x[j] > x[max])
            {
                max = j;
            }
        }
        if(max != i)
        {
            x [i] = x[i] ^ x[max];
            x [max] = x[i] ^ x[max];
            x [i] = x[i] ^ x[max];
        }
    }
}



void print_arr(int x[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%i ", x[i]);
    }
    printf("\n");
}