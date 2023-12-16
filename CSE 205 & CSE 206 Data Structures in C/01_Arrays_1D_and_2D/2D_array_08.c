//Sparse Matrices
#include<stdio.h>
int main()
{
    int i, j, row = 0, column = 0, non_zero_count = 0;
    int array[5][6]={
                    {0, 0, 0, 6, 0, 0},
                    {0, 7, 0, 0, 0, 0},
                    {0, 2, 0, 5, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {4, 0, 0, 0, 0, 0}};

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if(array[i][j] != 0) non_zero_count++;
        }
    }

    int sparse_matrix[3][non_zero_count + 1];
    sparse_matrix[0][0] = 5;
    sparse_matrix[1][0] = 6;
    sparse_matrix[2][0] = non_zero_count;
    
    row = 0;
    column = 1;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if(array[i][j] != 0)
            {
                sparse_matrix[row][column] = (i + 1);
                sparse_matrix[row + 1][column] = (j + 1);
                sparse_matrix[row + 2][column] = array[i][j];
                column++;
            }
        }
    }
    //Printing Sprse Matrix
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < non_zero_count + 1; j++)
        {
            printf("%d ", sparse_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}