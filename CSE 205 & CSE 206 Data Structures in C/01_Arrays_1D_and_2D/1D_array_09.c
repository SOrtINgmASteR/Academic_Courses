//Array Split
#include<stdio.h>
int main()
{
    int a[11]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, b[6], c[5];
    int i, j;
    for(i = 0, j = 0; j < 6; i++, j++)
    {
        b[j] = a[i];
    }

    for(j = 0; j < 5; i++, j++)
    {
        c[j] = a[i];
    }

    printf("b Array : ");
    for(i = 0; i < 6; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\nc Array : ");
    for(i = 0; i < 5; i++)
    {
        printf("%d ", c[i]);
    }
    return 0;
}