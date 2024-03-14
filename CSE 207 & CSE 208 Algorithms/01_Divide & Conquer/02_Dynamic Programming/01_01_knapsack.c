//0 - 1 Knapsack
#include<stdio.h>
int max(int a, int b) {return a >= b ? a : b;}
int main()
{
    int i, j, n = 5, c = 10;             //Number of Product & Capacity 
    int V[] = {7, 2, 1, 6, 12};          //Values 
    int W[] = {3, 1, 2, 4, 6};           //Weights
    int dp[n + 1][c + 1];

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= c; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(j < W[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else if(j >= W[i - 1])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i - 1]] + V[i - 1]);
            }
        }
    }
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= c; j++)
        {
            printf("%3d", dp[i][j]);
        }
        puts("\n");
    }
    i = n, j = c;
    while(i > 0 && j > 0)
    {
        if(dp[i][j] != dp[i - 1][j])
        {
            printf("Picked %dth Product\n", i);
            j -= W[i - 1];
            i--;
        }
        else
        {
            i--;
        }
    }
    return 0;
}