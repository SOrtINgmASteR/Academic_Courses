//Replacing / Upadating / Overriding value 
#include<stdio.h>
int main()
{
    int i, n, array[100000], flag = 0;
    int replacing_value, replace_value;

    printf("How many elements in the array : ");
    scanf("%d", &n);

    printf("Enter %d Numbers : ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter The Value to replace : ");
    scanf("%d", &replace_value);

    printf("Enter The Value to replace with : ");
    scanf("%d", &replacing_value);

    for (i = 0; i < n; i++)
    {
        if(array[i] == replace_value)
        {
            array[i] = replacing_value;
            flag = 1;
        }
    }

    if(flag == 0) printf("The replac Value %d wasn't found.", replace_value);
    else
    {
        printf("Array after replacing %d with %d : ", replace_value, replacing_value);
        for(i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    return 0;
}