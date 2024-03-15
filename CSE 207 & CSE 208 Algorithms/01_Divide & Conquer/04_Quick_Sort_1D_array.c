//Quick Sort
//Time Complexity ==> O(nlog(n))
//Space Complexity ==> O(log n)
#include<stdio.h>
int partition(int a[], int left, int right)
{
    int i, j, temp, pivot;
    pivot = a[left];
    i = left;
    j = right;
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
    a[j] = a[left];
    a[left] = temp;
    return j;
}
void quick_sort(int a[], int left, int right)
{
    if(left < right)
    {
        int pivot_index;
        pivot_index = partition(a, left, right);
        quick_sort(a, left, pivot_index - 1);
        quick_sort(a, pivot_index + 1, right);
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