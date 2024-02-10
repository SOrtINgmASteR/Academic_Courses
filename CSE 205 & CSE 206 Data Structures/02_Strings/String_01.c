//String Decalaration & Initialization
#include<stdio.h>
#include<string.h>
int main()
{
    char name1[100] = {'P', 'r', 'i', 'o', 'm'};
    char name2[100] = "Priom";
    
    printf("%s\n", name1);
    printf("%s\n", name2);
    
    puts(name1);
    puts(name2);
    return 0;
}