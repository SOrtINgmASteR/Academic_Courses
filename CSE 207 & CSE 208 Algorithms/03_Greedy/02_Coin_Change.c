//Coin Change
#include<stdio.h>
int coin_frequency[5];

int coin_change(int coins[], int amount, int i) 
{
    if (amount == 0) return 0;
    if (coins[i] > amount) 
    {
        return coin_change(coins, amount, i + 1);
    }
    coin_frequency[i]++;
    return 1 + coin_change(coins, amount - coins[i], i);
}

int main()
{
    int i, amount = 117, coins[5] = {50, 20, 10, 5, 1}; 

    int number_of_coins = coin_change(coins, amount, 0);
    printf("Number of coins needed is %d\n", number_of_coins);

    printf("Coin Froquency : \n");
    for(i = 0; i < 5; i++)
    {
        printf("%dx%d ", coins[i], coin_frequency[i]);
    }
    printf("\n");
    return 0;
}