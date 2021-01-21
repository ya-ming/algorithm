#ifndef _BINARYSEARCH_
#define _BINARYSEARCH_

#include <iostream>

using namespace std;

namespace BinarySearch
{
    //User function template for C++
    class Solution
    {
    public:
        // Function to find element in sorted array
        // arr: input array
        // N: size of array
        // K: element to be searche
        int searchInSorted(int arr[], int n, int k)
        {
            int left = 0;
            int right = n - 1;
            int mid = n / 2;
            while (left <= right)
            {
                if (arr[mid] == k)
                {
                    return mid;
                }
                else if (arr[mid] < k)
                {
                    left = mid + 1;
                    mid = (left + right) / 2;
                }
                else if (arr[mid] > k)
                {
                    right = mid - 1;
                    mid = (left + right) / 2;
                }
            }
            return -1;
        }

        int binarySearch(int arr[], int l, int r, int k)
        {
            if (r >= l)
            {
                int mid = l + (r - l) / 2;

                if (arr[mid] == k)
                    return mid;

                if (arr[mid] > k)
                    return binarySearch(arr, l, mid - 1, k);

                if (arr[mid] < k)
                    return binarySearch(arr, mid + 1, r, k);
            }

            return -1;
        }
    };
} // namespace BinarySearch

#endif