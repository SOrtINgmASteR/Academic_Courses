//Print from n to 1 then 1 to n
//5 4 3 2 1 1 2 3 4 5
#include<stdio.h>
void function(int n)
{
    if(n == 0) return;
    printf("%d ", n);
    function(n - 1);
    printf("%d ", n);
}

int main()
{
    function(5);
    
    return 0;
}