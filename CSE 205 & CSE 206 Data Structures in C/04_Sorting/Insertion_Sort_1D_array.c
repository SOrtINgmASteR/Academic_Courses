//Insertion Sort
//Time Complexity ==> O(n^2)
#include<stdio.h>
int main()
{
    int array[] = {10, -6, 8, -2, -60, 30, -20, 7, 3, 1};
    int i, j, n = 10, temp; 

    for(i = 1; i < n; i++)
    {
        temp = array[i];
        for(j = i - 1; (j >=0) && (array[j] > temp); j--)
        {
            array[j + 1] = array[j];
        }
        array[j + 1] = temp;
    }
    for(i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}