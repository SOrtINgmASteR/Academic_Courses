#include<stdio.h>

void function(int a[])
{
    a[2] = 1000;
    printf("%d\n", a[25]);
}

int main()
{
    int a[5] = {8, 3, 1, -5, -10};
    function(a);
    printf("%d", a[2]);
    
    return 0;
}