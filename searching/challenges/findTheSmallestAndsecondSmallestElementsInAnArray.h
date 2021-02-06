#ifndef FIND_THE_SMALLEST_AND_SECOND_SMALLEST_ELEMENTS_IN_AN_ARRAY
#define FIND_THE_SMALLEST_AND_SECOND_SMALLEST_ELEMENTS_IN_AN_ARRAY

#include <algorithm>

// Find the smallest and second smallest elements in an array
// 1) Initialize both first and second smallest as INT_MAX
//    first = second = INT_MAX
// 2) Loop through all the elements.
//    a) If the current element is smaller than first, then update first 
//        and second. 
//    b) Else if the current element is smaller than second then update 
//     second
bool findTheSmallestAndsecondSmallestElementsInAnArray(int arr[], int n, int &s1, int &s2)
{
    if (n < 2)
        return false;
    
    s1 = s2 = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < s1)
        {
            s2 = s1;
            s1 = arr[i];
        }
        else if (arr[i] < s2 && arr[i] != s1)
        {
            s2 = arr[i];
        }
    }
    if (s2 == INT_MAX)
        return false;

    return true;
}

#endif