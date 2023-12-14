//2d Array - Taking User input element by element
#include<stdio.h>
int main()
{
    int array[3][3];

    scanf("%d %d %d", &array[0][0], &array[0][1], &array[0][2]);
    scanf("%d %d %d", &array[1][0], &array[1][1], &array[1][2]);
    scanf("%d %d %d", &array[2][0], &array[2][1], &array[2][2]);
    printf("\n");
    printf("%d %d %d\n", array[0][0], array[0][1], array[0][2]);
    printf("%d %d %d\n", array[1][0], array[1][1], array[1][2]);
    printf("%d %d %d\n", array[2][0], array[2][1], array[2][2]);

    return 0;
}
