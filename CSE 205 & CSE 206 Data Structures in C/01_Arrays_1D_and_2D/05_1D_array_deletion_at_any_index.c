//Deletion in array at any Index
#include<stdio.h>
int main()
{
    int i, j, n, array[100000], flag = 0;
    int deletion_index;

    printf("Enter array size : ");
    scanf("%d", &n);

    printf("Enter %d numbers : ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter the deletion Index : ");
    scanf("%d", &deletion_index);

    for(i = deletion_index; i < n - 1; i++)
    {
        array[i] = array[i+1];
    }
    n--;

    printf("Array after Deletion : ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}