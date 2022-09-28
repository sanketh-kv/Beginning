#include <stdio.h>

void sort(int a[], int lo, int hi);
void merge(int a[], int lo, int mid, int hi);
void print_arr(int x[], int n);

int main (void)
{
    int a[] = {6,4,2,5,3,1,8};
    int lo = 0;
    int hi = (sizeof(a) / sizeof(a[0])) - 1;
    printf("Before sorting: ");
    print_arr(a, hi + 1);
    sort(a, lo, hi);
    printf("After  sorting: ");
    print_arr(a, hi + 1);
    return 0;
}

//Recursive sort function (divide and conquer)
void sort(int a[], int lo, int hi)
{
    int mid =  (lo + hi) / 2;
    if(lo != hi)
    {
        sort(a, lo, mid);
        sort(a, mid + 1, hi);
        merge(a, lo, mid, hi);
    }

}

//Merging sorted halves
void merge(int a[], int lo, int mid, int hi)
{
    int i = lo;
    int j = mid + 1;
    int k = 0;
    int b[hi - lo + 1];

    while(i <= mid && j <= hi)
    {
        if(a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while(i <= mid)
    {
        b[k] = a[i];
        k++; i++;
    }

    while(j <= hi)
    {
        b[k] = a[j];
        k++; j++;
    }

    //Copying elements from temp array to original array
    for(int x = 0; x < hi - lo + 1; x++)
    {
        a[lo + x] = b[x];
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