//Quaternary Search
//Time Complexity ==> O(4 based log(n))
#include<stdio.h>
int main()
{
    int array[9] = {-5, -3, 2, 8, 14, 18, 30, 65, 82};
    int i, low = 0, high = 8, mid1, mid2, mid3, search_value = 2, flag = 0;
    while(low <= high)
    {
        mid1 = low + (high - low) / 4;
        mid2 = low + (high - low) / 2;
        mid3 = high - (high - low) / 4;
        if(array[mid1] == search_value)
        {
            printf("%d value is at %d index.\n", search_value, mid1);
            flag = 1;
            break;
        }
        else if(array[mid2] == search_value)
        {
            printf("%d value is at %d index.\n", search_value, mid2);
            flag = 1;
            break;
        }
        else if(array[mid3] == search_value)
        {
            printf("%d value is at %d index.\n", search_value, mid3);
            flag = 1;
            break;
        }
        else if(search_value < array[mid1])
        {
            high = mid1 - 1;
        }
        else if(search_value > array[mid3])
        {
            low = mid3 + 1;
        }
        else if(search_value > array[mid1] && search_value < array[mid2])
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
        else if(search_value > array[mid2] && search_value < array[mid3])
        {
            low = mid2 + 1;
            high = mid3 - 1;
        }
    }
    if(flag == 0) printf("%d value not found in the array\n", search_value);
    return 0;
}