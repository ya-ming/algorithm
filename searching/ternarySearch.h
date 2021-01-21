#ifndef _TERNARYSEARCH_
#define _TERNARYSEARCH_

#include <iostream>

using namespace std;

namespace TernarySearch
{
    //User function template for C++
    class Solution
    {
    public:
        int ternarySearch(int arr[], int l, int r, int k)
        {
            if (r >= l)
            {
                int mid1 = l + (r - l) / 3;
                int mid2 = mid1 + (r - l) / 3;

                // If x is present at the mid1 
                if (arr[mid1] == k)
                    return mid1;
                
                // If x is present at the mid2 
                if (arr[mid2] == k)
                    return mid2;

                // If x is present in left one-third 
                if (arr[mid1] > k)
                    return ternarySearch(arr, l, mid1 - 1, k);

                // If x is present in right one-third 
                if (arr[mid2] < k)
                    return ternarySearch(arr, mid2 + 1, r, k);

                // If x is present in middle one-third 
                return ternarySearch(arr, mid1 + 1, mid2 - 1, k);
            }

            return -1;
        }
    };
} // namespace TernarySearch

#endif