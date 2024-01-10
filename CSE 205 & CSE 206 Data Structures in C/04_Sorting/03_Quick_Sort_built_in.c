//Quick Sort Built in
#include<stdio.h>
#include<stdlib.h>
int ascending(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return x - y;
}
int descending(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return y - x;
}

int main()
{
    int i, n = 8, array[10] = {95, -10, 25, 11, 9, 5, 4, 21};
    qsort(array, n, sizeof(int), ascending);
    printf("Ascending Order : \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    qsort(array, n, sizeof(int), descending);
    printf("Descending Order : \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}