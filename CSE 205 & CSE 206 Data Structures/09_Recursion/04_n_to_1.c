//Print from n to 1
//5 4 3 2 1
#include<stdio.h>
void function(int n)
{
    if(n == 0) return;
    printf("%d ", n);
    function(n - 1);
}

int main()
{
    function(5);
    
    return 0;
}