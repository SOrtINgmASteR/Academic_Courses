#include<stdio.h>
int main()
{
    int a = 5, *p, *p2;
    p = &a;
    printf("%d %d\n", &a, a);
    printf("%d %d\n", p, *p);
    return 0;
}