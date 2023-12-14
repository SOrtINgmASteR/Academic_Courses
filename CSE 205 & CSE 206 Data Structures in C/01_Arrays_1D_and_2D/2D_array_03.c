//2D Array - Taking user input using nested loops
#include<stdio.h>
int main()
{
    int i, j , array[3][3];

    printf("Enter Array Elements : \n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    printf("The Array Elements are : \n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}