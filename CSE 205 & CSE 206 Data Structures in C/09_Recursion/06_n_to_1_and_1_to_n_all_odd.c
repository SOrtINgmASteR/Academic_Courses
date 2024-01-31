//Print n to 1 then 1 to n all odd
//7 5 3 1 1 3 5 7
#include<stdio.h>
void function(int n)
{
    if(n <= 0) return;
    printf("%d ", n);
    function(n - 2);
    printf("%d ", n);
}

int main()
{
    function(7);
    return 0;
}