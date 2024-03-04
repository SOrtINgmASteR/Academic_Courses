//Longest Common Subsequence
#include<stdio.h>
#include<string.h>
int max(int a, int b) {return a >= b ? a : b;}
int main()
{
    char X[] = {'-', 'A', 'C', 'G', 'T', 'C', 'C', 'G', 'C', 'T', 'C', 'G'};
    char Y[] = {'-', 'A', 'T', 'C', 'T', 'C', 'T'};
    int i, j, l1 = 12, l2 = 7;
    int array[l2 + 1][l1 + 1];
    for(i = 0; i <= l2; i++)
    {
        for(j = 0; j <= l1; j++)
        {
            if(i == 0 || j == 0) array[i][j] = 0;
        }
    }
    for(i = 1; i <= l2; i++)
    {
        for(j = 1; j <= l1; j++)
        {
            if(Y[i] == X[j])
            {
                array[i][j] = array[i - 1][j - 1] + 1;
            }
            else
            {
                array[i][j] = max(array[i - 1][j], array[i][j - 1]);
            }
        }
    }
    for(i = 0; i <= l2; i++)
    {
        for(j = 0; j <= l1; j++)
        {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }
    char lcs[34];
    int k = 0;
    i = l2, j = l1;
    while(i != 0 || j != 0)
    {
        if(array[i][j] == array[i - 1][j]) i--;
        else if(array[i][j] == array[i][j - 1]) j--;
        else
        {
            printf("%c ", Y[i]);
            lcs[k] = Y[i];
            i--;
            j--;
            k++;
        }
    }
    lcs[k] = '\0';
    puts(strrev(lcs));
    return 0;
}