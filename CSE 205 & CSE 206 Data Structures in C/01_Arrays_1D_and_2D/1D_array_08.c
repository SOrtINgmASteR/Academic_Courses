//Deletion in array using value
#include<stdio.h>
int main()
{
    int i, j, n, array[100000], flag = 0;
    int deletion_value;

    printf("Enter array size : ");
    scanf("%d", &n);

    printf("Enter %d numbers : ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter the deletion value in the Array : ");
    scanf("%d", &deletion_value);

    for(i = 0; i < n; i++)
    {
        if(array[i] == deletion_value)
        {
            for(j = i; j < n - 1; j++)
            {
                array[j] = array[j+1];
            }
            n--;
            i--;
        }
    }

    printf("Array after Deletion : ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}