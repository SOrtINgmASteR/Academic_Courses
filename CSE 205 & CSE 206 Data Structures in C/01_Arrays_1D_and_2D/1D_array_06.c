//Insertion in array using value 
#include<stdio.h>
int main()
{
    int i, j, n, array[100000], flag = 0;
    int insertion_value, insertion_value_in_array;

    printf("Enter array size : ");
    scanf("%d", &n);

    printf("Enter %d numbers : ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter the value to be replaced : ");
    scanf("%d", &insertion_value_in_array);
    printf("Enter the insertion value : ");
    scanf("%d", &insertion_value);

    for(i = 0; i < n; i++)
    {
        if(array[i] == insertion_value_in_array)
        {
            for(j = n; j > i; j--)
            {
                array[j] = array[j-1];
            }
            array[j] = insertion_value;
            n++;
            i++;
            flag = 1;
        }
    }
    if(flag == 1)
    {
        printf("Array after Insertion : ");
        for(i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Insertion didn't happend\n");
                for(i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    return 0;
}