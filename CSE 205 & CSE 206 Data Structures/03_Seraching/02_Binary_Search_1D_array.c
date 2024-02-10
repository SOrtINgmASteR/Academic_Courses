//Binary Search
//Time Complexity => O(log(n))
#include<stdio.h>
int main()
{
    int array[9] = {-5, -3, 2, 8, 14, 18, 30, 65, 82};
    int i, low = 0, high = 8, mid, search_value = 750, flag = 0;
    while(low <= high)
    {
        mid = low + (high - low)/2;
        if(array[mid] == search_value)
        {
            printf("%d value is at %d index.\n", search_value, mid);
            flag = 1;
            break;
        }
        else if(search_value > array[mid])
        {
            low = mid + 1;
        }
        else if(search_value < array[mid])
        {
            high = mid - 1;
        }
    }
    if(flag == 0) printf("%d value not found in the array\n", search_value);
    return 0;
}