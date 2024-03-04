//Binary Serach Recursive Method
#include<stdio.h>
int binary_search(int array[], int left, int right, int search_value)
{
    int mid;
    if(left <= right)
    {
        mid = left + (right - left) / 2;
        if(array[mid] == search_value)
        {
            return mid;
        }
        else if(array[mid] > search_value)
        {
            return binary_search(array, left, mid - 1, search_value);
        }
        else if(array[mid] < search_value)
        {
            return binary_search(array, mid + 1, right, search_value);
        }
    }
    return -1;
}

int main()
{
    int array[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int left = 0, right = 9, index, search_value = 100;
    index = binary_search(array, left, right, search_value);

    if(index == -1) printf("%d value is not found in the array\n", search_value);
    else printf("%d is in %d index in the array\n", search_value, index);
    return 0;
}