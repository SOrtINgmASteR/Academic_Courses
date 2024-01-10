//Array Merge
#include<stdio.h>
int main()
{
    int a[11], b[6] = {1, 2, 3, 4, 5, 6}, c[5] = {7, 8, 9, 10, 11};
    int i, j;
    for(i = 0, j = 0; j < 6; i++, j++)
    {
        a[i] = b[j];
    }
    for(j = 0; j < 5; i++, j++)
    {
        a[i] = c[j];
    }
    printf("a array : ");
    for(i = 0; i < 11; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}