#ifndef _EXPONENTIALSEARCH_
#define _EXPONENTIALSEARCH_

#include <iostream>
#include <algorithm>
#include "binarySearch.h"

using namespace std;

namespace ExponentialSearch
{
    //User function template for C++
    class Solution
    {
    public:
        int exponentialSearch(int arr[], int n, int x)
        {
            if (arr[0] == x)
                return 0;
            
            int i = 0;
            for (i = 1; i < n && arr[i] <= x; i *= 2)
            {}

            BinarySearch::Solution s;
            return s.binarySearch(arr, i/2, min(i, n - 1), x);
        }
    };
} // namespace ExponentialSearch

#endif