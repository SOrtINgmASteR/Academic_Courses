//Merge Sort
//Time Complexity ==> O(nlog(n))
//Space Complexity ==> O(log n)
#include<stdio.h>
void merge(int a[], int l, int mid, int h)
{
    int array[100000];
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= h)
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
    for( ;i <= mid; i++)
    {
        array[k] = a[i];
        k++;
    }
    for(  ;j <= h; j++)
    {
        array[k] = a[j];
        k++;
    }
    for(i = l, j = 0; i <= h; i++, j++)
    {
        a[i] = array[j];
    }
}

void mergeSort(int a[], int l, int h)
{
    int mid;
    if(l < h)
    {
        mid = (l + h) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        merge(a, l, mid, h);
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