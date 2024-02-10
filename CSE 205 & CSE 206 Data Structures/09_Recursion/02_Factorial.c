//Factorial
#include<stdio.h>
int function(int n)
{
    if(n == 1) return 1;
    return n * function(n -1);
}

int main()
{
    printf("%d\n", function(5));
    printf("%d\n", function(7));
    return 0;
}