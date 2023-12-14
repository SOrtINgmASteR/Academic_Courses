//Insertion in array at any Index
#include<stdio.h>
int main()
{
    int i, n, array[100000], flag = 0;
    int index, insertion_value;
    
    printf("Enter array size : ");
    scanf("%d", &n);

    printf("Enter %d numbers : ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter Insertion index : ");
    scanf("%d", &index);
    printf("Enter Insertion value : ");
    scanf("%d", &insertion_value);

    if(index>=0 && index<=n-1)
    {
        for(i = n; i > index; i--)
        {
            array[i] = array[i-1];
        }
        array[i] = insertion_value;
        flag = 1;
        n++;
    }

    if(flag == 1)
    {
        printf("After Insertion : ");
        for(i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
    }
    else if(flag == 0)
    {
        printf("No Insertion happend, Array : ");
        for(i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
    }
    return 0;
}