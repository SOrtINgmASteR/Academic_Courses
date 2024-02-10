//Column in 2D Array 
#include<stdio.h>
int main()
{
    int i, j, array[3][3] = {{101, 102, 103}, {104, 105, 106}, {107, 108, 109}};
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(j == 1)
            {
                printf("%d\n", array[i][j]);
            }
        }
    }
    return 0;
}
