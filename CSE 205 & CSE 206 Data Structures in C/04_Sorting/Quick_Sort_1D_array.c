//Quick Sort
//Time Complexity ==> O(nlog(n))
//Space Complexity ==> O(log n)
#include<stdio.h>
int partition(int a[], int low, int high)
{
    int i, j, temp, pivot = a[low];
    i = low, j = high;
    while(i < j)
    {
        while(a[i] <= pivot) 
        {
            i++;
        }
        while(a[j] > pivot) 
        {
            j--;
        }
        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}
void quick_sort(int a[], int low, int high)
{
    if(low >= high) return;
    int pivot_index;
    pivot_index = partition(a, low, high);
    quick_sort(a, low, pivot_index - 1);
    quick_sort(a, pivot_index + 1, high);
}
int main()
{
    int i,  a[10] = {21, 28, 56, 10, 6, 8, -10, 1, -5, 2};
    quick_sort(a, 0, 9);
    for(i = 0; i < 9; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}