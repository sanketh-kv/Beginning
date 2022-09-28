#include <stdio.h>

void sort(int x[], int n);
void print_arr(int x[], int n);

int main (void)
{
    int x[] = {5, 2, 4, 1, 0, 3, 6, 9, 8, 7};
    int n = sizeof(x) / 4;
    printf("Before sorting: ");
    print_arr(x, n);
    sort(x, n);
    printf("After  sorting: ");
    print_arr(x, n);
}



void sort(int x[], int n)
{
    for(int i = 0; i < n; i++) //ex: for largest element at 0, n-1 steps needed to reach end
    {
        int swap_counter = 0;
        for(int j = 0; j < n - 1 - i; j++) //perform swapping till last but one term because nothing to compare at last term iteration
        {
            if(x[j] > x[j + 1]) //swapping using xor operator
            {
                x[j] = x[j] ^ x[j + 1];
                x[j + 1] = x[j] ^ x[j + 1];
                x[j] = x[j] ^ x[j + 1];
                swap_counter++;
            }
        }
        if(swap_counter == 0)
        {
            break;
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