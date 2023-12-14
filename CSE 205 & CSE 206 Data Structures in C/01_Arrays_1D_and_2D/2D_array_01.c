//2d Array - Declaration & Initialization
#include<stdio.h>
int main()
{
    int array1[4][4];
    int array2[4][4] = {{101, 102, 103, 104}, {105, 106, 107, 108}, {109, 110, 111, 112}, {123, 124, 125, 126}};

    array1[0][0] = 1;
    array1[0][1] = 2;
    array1[0][2] = 3;
    array1[0][3] = 4;

    array1[1][0] = 5;
    array1[1][1] = 6;
    array1[1][2] = 7;
    array1[1][3] = 8;

    array1[2][0] = 9;
    array1[2][1] = 10;
    array1[2][2] = 11;
    array1[2][3] = 12;

    array1[3][0] = 13;
    array1[3][1] = 14;
    array1[3][2] = 15;
    array1[3][3] = 16;
    
    printf("Array 1 : \n");
    printf("%d %d %d %d\n", array1[0][0], array1[0][1], array1[0][2], array1[0][3]);
    printf("%d %d %d %d\n", array1[1][0], array1[1][1], array1[1][2], array1[1][3]);
    printf("%d %d %d %d\n", array1[2][0], array1[2][1], array1[2][2], array1[2][3]);
    printf("%d %d %d %d\n", array1[3][0], array1[3][1], array1[3][2], array1[3][3]);
    
    printf("\nArray 2 : \n");
    printf("%d %d %d %d\n", array2[0][0], array2[0][1], array2[0][2], array2[0][3]);
    printf("%d %d %d %d\n", array2[1][0], array2[1][1], array2[1][2], array2[1][3]);
    printf("%d %d %d %d\n", array2[2][0], array2[2][1], array2[2][2], array2[2][3]);
    printf("%d %d %d %d\n", array2[3][0], array2[3][1], array2[3][2], array2[3][3]);

    return 0;
}
