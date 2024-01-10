//Array - Declaration & Initialization
#include<stdio.h>
int main()
{
    int array1[5];
    array1[0] = 10;
    array1[1] = 20;
    array1[2] = 30;
    array1[3] = 40;
    array1[4] = 50;

    int array2[] = {10, 20, 30, 40, 50, 60};

    printf("Array 1 : ");
    printf("%d ", array1[0]);
    printf("%d ", array1[1]);
    printf("%d ", array1[2]);
    printf("%d ", array1[3]);
    printf("%d\n", array1[4]);

    printf("Array 2 : ");
    printf("%d ", array2[0]);
    printf("%d ", array2[1]);
    printf("%d ", array2[2]);
    printf("%d ", array2[3]);
    printf("%d\n", array2[4]);

    printf("%d byte\n", sizeof(array1));
    printf("%d byte\n", sizeof(array2));
    
    printf("%d byte\n", sizeof(int));
    printf("%d byte\n", sizeof(float));
    printf("%d byte\n", sizeof(long long int));
    printf("%d byte\n", sizeof(double));
    return 0;
}