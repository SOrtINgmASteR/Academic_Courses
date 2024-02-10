//Structure Define & Initialization (Global & Local)
#include<stdio.h>
struct mountains
{
    char name[100];
    int height;
};

int main()
{
    struct mountains m[5];
    int i;
    printf("Enter Mountain height & Name : \n");
    for(i = 0; i < 2; i++)
    {
        scanf("%d", &m[i].height);
        gets(m[i].name);
    }
    printf("\nMountain height & Names are : \n");
    for(i = 0; i < 2; i++)
    {
        printf("%d %s\n", m[i].height, m[i].name);
    }
    return 0;
}