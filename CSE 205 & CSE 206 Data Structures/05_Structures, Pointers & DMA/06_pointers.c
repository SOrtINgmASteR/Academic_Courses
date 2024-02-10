#include<stdio.h>
//Call by Value
void increment1(int a)
{
    a = a + 1;
}
//Call by Reference
void increment2(int *a)
{
    *a = *a + 1;
}
int main()
{
    int a = 5;
    increment1(a);
    printf("%d\n", a);
    increment2(&a);
    printf("%d\n", a);
    return 0;
}