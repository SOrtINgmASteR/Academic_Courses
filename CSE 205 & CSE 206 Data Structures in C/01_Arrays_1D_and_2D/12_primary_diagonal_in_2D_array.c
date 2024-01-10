//Primary Diagonal
#include<stdio.h>
int main()
{
    int i, j, array[4][4] = {
                            {10, 11, 12, 13}, 
                            {14, 15, 16, 17}, 
                            {18, 19, 20, 21}, 
                            {22, 23, 24, 25}};
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(j == i)
            {
                printf("%d ", array[i][j]);
            }
        }
    }
    return 0;
}