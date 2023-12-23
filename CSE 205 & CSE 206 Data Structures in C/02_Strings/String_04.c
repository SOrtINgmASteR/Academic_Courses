
#include<stdio.h>
#include<string.h>
int main()
{
    char names[100][100];
    int i;
    puts("Enter Names : ");
    for(i = 0; i < 5; i++)
    {
        gets(names[i]);
    }
    puts("Your Names : ");
    for(i = 0; i < 5; i++)
    {
        puts(names[i]);
    }
    return 0;
}