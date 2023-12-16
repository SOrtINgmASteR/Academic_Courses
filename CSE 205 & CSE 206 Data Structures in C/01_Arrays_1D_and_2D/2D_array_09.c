//Sparse Matrix Addition
#include<stdio.h>
int main()
{
    int sprase_matrix_1[3][7 + 1] = {
                                {5, 1, 1, 2, 4, 4, 5, 5},
                                {6, 2, 3, 3, 1, 5, 2, 5},
                                {7, 1, 2, 5, 1, 3, 7, 6}};
    int sprase_matrix_2[3][5 + 1] = {
                                {5, 1, 2, 3, 3, 5},
                                {6, 4, 2, 2, 4, 1},
                                {5, 6, 7, 2, 5, 4}};
    int matrix1_non_zero = 7, matrix2_non_zero = 5;
    int sub_sparse_matrix[3][matrix1_non_zero + matrix2_non_zero + 1], i, j, row = 0, column = 0;
    sub_sparse_matrix[row][column] = 5;
    sub_sparse_matrix[row + 1][column] = 6;
    column++;

    for(i = 1, j = 1; (i < matrix1_non_zero + 1) || (j < matrix2_non_zero + 1); )
    {
        if(sprase_matrix_1[0][i] < sprase_matrix_2[0][j])
        {
            sub_sparse_matrix[row][column] = sprase_matrix_1[row][i];
            sub_sparse_matrix[row + 1][column] = sprase_matrix_1[1][i];
            sub_sparse_matrix[row + 2][column] = sprase_matrix_1[2][i];
            i++;
            column++;
        }
        else if((sprase_matrix_1[0][i] == sprase_matrix_2[0][j]) && (sprase_matrix_1[1][i] < sprase_matrix_2[1][j]))
        {
            sub_sparse_matrix[row][column] = sprase_matrix_1[0][i];
            sub_sparse_matrix[row + 1][column] = sprase_matrix_1[1][i];
            sub_sparse_matrix[row + 2][column] = sprase_matrix_1[2][i];
            i++;
            column++;
        }
        else if(sprase_matrix_1[0][i] > sprase_matrix_2[0][j])
        {
            sub_sparse_matrix[row][column] = sprase_matrix_2[0][j];
            sub_sparse_matrix[row + 1][column] = sprase_matrix_2[1][j];
            sub_sparse_matrix[row + 2][column] = sprase_matrix_2[2][j];
            j++;
            column++;
        }
        else if((sprase_matrix_1[0][i] == sprase_matrix_2[0][j]) && (sprase_matrix_1[1][i] > sprase_matrix_2[1][j]))
        {
            sub_sparse_matrix[row][column] = sprase_matrix_2[0][j];
            sub_sparse_matrix[row + 1][column] = sprase_matrix_2[1][j];
            sub_sparse_matrix[row + 2][column] = sprase_matrix_2[2][j];
            j++;
            column++;
        }
        else if((sprase_matrix_1[0][i] == sprase_matrix_2[0][j]) && (sprase_matrix_1[1][i] == sprase_matrix_2[1][j]))
        {
            sub_sparse_matrix[row][column] = sprase_matrix_1[0][i];
            sub_sparse_matrix[row + 1][column] = sprase_matrix_1[1][i];
            sub_sparse_matrix[row + 2][column] = sprase_matrix_1[2][i] + sprase_matrix_2[2][j];
            i++;
            j++;
            column++;
        }
    }
    sub_sparse_matrix[row + 2][0] = column - 1;
    printf("Subtracted Sparse matrix : ");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < column; j++)
        {
            printf("%d ", sub_sparse_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}