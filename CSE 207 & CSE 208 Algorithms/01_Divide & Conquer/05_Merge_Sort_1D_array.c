//Merge Sort
//Time Complexity ==> O(nlog(n))
//Space Complexity ==> O(log n)
#include<stdio.h>
void merge(int a[], int left, int mid, int right)
{
    int array[100000];
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right)
    {
        if(a[i] < a[j])
        {
            array[k] = a[i];
            k++;
            i++;
        }
        else 
        {
            array[k] = a[j];
            k++;
            j++;
        }
    }
    while(i <= mid)
    {
        array[k] = a[i];
        k++;
        i++;
    }
    while(j <= right)
    {
        array[k] = a[j];
        k++;
        j++;
    }
    for(i = left, j = 0; i <= right; i++, j++)
    {
        a[i] = array[j];
    }
}

void mergeSort(int a[], int left, int right)
{
    int mid;
    if(left < right)
    {
        mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    int i, a[10]={500, 95, 34, 11, -200, 20, -5, -7, -10, -100};
    int n = 10;
    printf("Before Sorting : ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    mergeSort(a, 0, 9);

    printf("After Sorting : ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}