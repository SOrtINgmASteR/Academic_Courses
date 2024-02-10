//String Functions
#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100] = "This is a string.", str2[100] = "This is another string.", str3[100] = "This is another string.";

    strcat(str1, "Sky full of stars.");
    puts(str1);

    strcpy(str1, "Bag full of Money.");
    puts(str1);

    if(strcmp(str3, str2) == 0) printf("Same");
    else printf("Not Same");
    
    strcpy(str1, "\0");

    int l = strlen(str1);
    printf("\nlength = %d\n", l);
    return 0;
}