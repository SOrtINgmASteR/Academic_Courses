//Bubble Sort
//Time Complexity ==> O(n^2)
#include<stdio.h>
int main()
{
    int array[] = {10, -6, 8, -2, 6, 30, -20, 7, 3, 1};
    int i, j, n = 10, temp; 

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - 1; j++)
        {
            if(array[j + 1] < array[j])
            {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}