#include <stdio.h>

void sort(int a[], int start, int end);
void print_arr(int a[], int length);
int partition(int a[], int start, int end);
void swap(int a[], int x, int y);

int main (void)
{
    int a[] = {4, 3, 8, 9, 4, 2, 6};
    int length = (sizeof(a) / sizeof(a[0]));
    printf("Before Sorting: \n");
    print_arr(a, length);
    int start = 0;
    int end = length - 1;
    sort(a, start, end);
    printf("After Sorting: \n");
    print_arr(a, length);
    return 0;
}

void sort(int a[], int start, int end)
{
    if(start < end)
    {
        int pIndex = partition(a, start, end);
        sort(a, start, pIndex - 1);
        sort(a, pIndex + 1, end);
    }
}

void print_arr(int a[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%i ", a[i]);
    }
    printf("\n");
}

int partition(int a[], int start, int end)
{
    int pIndex = start;
    int pivot = a[end];
    for (int i = start; i < end; i++)
    {
        if (a[i] < pivot)
        {
            swap(a, i, pIndex);
            pIndex++;
        }
    }
    swap(a, pIndex, end);
    return pIndex;
}

void swap(int a[], int x, int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}