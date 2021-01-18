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
                    return mid + 1;
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
    };
} // namespace BinarySearch