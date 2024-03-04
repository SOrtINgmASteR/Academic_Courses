//Quick Sort
//Time Complexity ==> O(nlog(n))
//Space Complexity ==> O(log n)
#include<stdio.h>
int partition(int a[], int low, int high)
{
    int i, j, temp, pivot;
    pivot = a[low];
    i = low;
    j = high;
    while(i < j)
    {

        while(a[i] <= pivot) i++;
        while(a[j] > pivot) j--;
        if(i < j)
        {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    temp = a[j];
    a[j] = a[low];
    a[low] = temp;
    return j;
}
void quick_sort(int a[], int low, int high)
{
    if(low < high)
    {
        int pivot_index;
        pivot_index = partition(a, low, high);
        quick_sort(a, low, pivot_index - 1);
        quick_sort(a, pivot_index + 1, high);
    }
}
int main()
{
    int i,  a[10] = {9, 4, 6, 15, 6, 5, 14, 11, -10, -21};
    int n = 10;

    printf("Before Sorting : ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    quick_sort(a, 0, 9);

    printf("After Sorting : ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}