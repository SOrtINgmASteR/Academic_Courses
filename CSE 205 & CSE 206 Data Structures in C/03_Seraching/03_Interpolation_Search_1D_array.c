//Interpolation Search
//Time Complexity => O(log(log(n)))
#include<stdio.h>
int main()
{
    int array[9] = {20, 40, 60, 80, 100, 120, 140, 160, 180};
    int low = 0, high = 8, pos, search_value = 120, flag = 0;
    while((low <= high) && ((array[low] <= search_value) && (search_value <= array[high])))
    {
        pos = low + (((high - low) * (search_value - array[low])) / (array[high] - array[low]));
        if(array[pos] == search_value)
        {
            printf("%d value is at %d index.\n", search_value, pos);
            flag = 1;
            break;
        }
        else if(search_value > array[pos])
        {
            low = pos + 1;
        }
        else if(search_value < array[pos])
        {
            high = pos - 1;
        }
    }
    if(flag == 0) printf("%d value not found in the array.\n", search_value);
    return 0;
}