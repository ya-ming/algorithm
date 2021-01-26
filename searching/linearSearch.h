#ifndef _LINEARSEARCH_
#define _LINEARSEARCH_

#include <iostream>

using namespace std;

namespace LinearSearch
{
    //User function template for C++
    class Solution
    {
    public:
        int search(int arr[], int n, int k)
        {
            // code here
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == k)
                    return i;
            }
            return -1;
        }

        // Improve Linear Search Worst-Case Complexity
        //      if element Found at last  O(n) to O(1)
        //      if element Not found O(n) to O(n/2)
        int improvedSearch(int arr[], int n, int k)
        {
            int left = 0;
            int right = n - 1;

            for (left = 0; left <= right;)
            {
                if (arr[left] == k)
                {
                    return left;
                }

                if (arr[right] == k)
                {
                    return right;
                }

                left++;
                right--;
            }

            return -1;
        }

        // recursive function to search x in arr[l...r]
        int recSearch(int arr[], int l, int r, int k)
        {
            if (r < l)
                return -1;
            if (arr[l] == k)
                return l;
            if (arr[r] == k)
                return r;
            return recSearch(arr, l + 1, r - 1, k);
        }
    };
}; // namespace LinearSearch

#endif