//Linear Search
//Time complexity => O(n)
#include<stdio.h>
int main()
{
    int array[7] = {9, -25, 120, 11, -18, 120, 21};
    int i, j, n = 7, search_value = -18, flag = 0;
    for(i = 0; i < n; i++)
    {
        if(array[i] == search_value)
        {
            printf("%d value is at %d index.\n", search_value, i);
            flag = 1;
        }
    }
    if(flag == 0) printf("The value %d wasn't found\n", search_value);
    return 0;
}