//GCD & LCM
#include<stdio.h>
int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main()
{
    printf("%d\n", gcd(4, 12));
    printf("%d\n", gcd(6, 12));
    printf("%d\n", gcd(18, 12));
    printf("%d\n", gcd(25, gcd(30, gcd(50, 40))));
}