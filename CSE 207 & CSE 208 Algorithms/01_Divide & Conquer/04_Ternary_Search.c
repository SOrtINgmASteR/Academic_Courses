//Ternary Serach Recursive Method
#include<stdio.h>
int ternary_search(int array[], int left, int right, int search_value)
{
    int mid1, mid2;
    if(left <= right)
    {
        mid1 = left + (right - left) / 3;
        mid2 = right - (right - left) / 3;
        if(array[mid1] == search_value)
        {
            return mid1;
        }
        else if(array[mid2] == search_value)
        {
            return mid2;
        }
        else if(array[mid1] > search_value)
        {
            return ternary_search(array, left, mid1 - 1, search_value);
        }
        else if(array[mid2] < search_value)
        {
            return ternary_search(array, mid2 + 1, right, search_value);
        }
        else if(array[mid1] < search_value && array[mid2] > search_value)
        {
            return ternary_search(array, mid1 + 1, mid2 - 1, search_value);
        }
    }
    return - 1;
}

int main()
{
    int array[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int left = 0, right = 9, index, search_value = 20;
    index = ternary_search(array, left, right, search_value);
    
    if(index == -1) printf("%d value is not found in the array\n", search_value);
    else printf("%d is in %d index in the array\n", search_value, index);
    return 0;
}