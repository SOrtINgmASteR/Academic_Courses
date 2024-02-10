//Fibonacci
//0 1 1 2 3 5 8 13 21 34 55 89 144 233 377
#include<stdio.h>
int function(int n)
{
    if(n == 1) return 0;
    else if(n == 2) return 1;
    return function(n - 1) + function(n - 2);
}

int main()
{
    printf("%d\n", function(5));
    printf("%d\n", function(7));
    printf("%d\n", function(9));
    return 0;
}