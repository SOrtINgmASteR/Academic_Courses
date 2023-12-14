//Array - Taking input from the user using loops
#include<stdio.h>
int main()
{
    int i, array[5];

    printf("Enter 5 elements : ");
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("The elements are : ");
    for(i = 0; i < 5; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

