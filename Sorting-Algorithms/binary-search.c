#include <stdio.h>
#include <cs50.h>

void search(int arr[], int s, int e, int x);

int main (void)
{
    int a[] = { 6, 7, 8, 9, 10, 11, 14, 15, 17, 19, 22, 23, 25, 28, 30 };
    int s = 0;
    int e = (sizeof(a) / 4) - 1;
    int x = get_int("Number: ");

    search(a, s, e, x);
}

void search(int arr[], int s, int e, int x)
{
    if (s <= e)
    {
    int mid = (s + e) / 2;

    if (x == arr[mid])
    {
        printf("Found\n");
    }
    else if (x < arr[mid])
    {
        e = mid - 1;
        search (arr, s, e, x);
    }
    else if (x > arr[mid])
    {
        s = mid + 1;
        search (arr, s, e, x);
    }
    }
    else
    {
        printf("Not found\n");
    }
}
