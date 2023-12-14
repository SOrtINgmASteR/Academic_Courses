//Array - Taking input from the user element by element
#include<stdio.h>
int main()
{
    int array[5];

    printf("Enter 5 elements : ");
    scanf("%d", &array[0]);
    scanf("%d", &array[1]);
    scanf("%d", &array[2]);
    scanf("%d", &array[3]);
    scanf("%d", &array[4]);

    printf("The elements are : ");
    printf("%d ", array[0]);
    printf("%d ", array[1]);
    printf("%d ", array[2]);
    printf("%d ", array[3]);
    printf("%d ", array[4]);

    return 0;
}

