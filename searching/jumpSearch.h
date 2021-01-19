#include <iostream>
#include <algorithm>

using namespace std;

namespace JumpSearch
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
            int step = sqrt(n);
            int index;
            int prev = 0;

            // Finding the block where element is
            // present (if it is present)
            while (arr[min(index, n) - 1] < n)
            {
                prev = index;
                index += step;
                if (prev >= n)
                    return -1;
            }

            // Doing a linear search for x in block 
            // beginning with prev.
            while (arr[prev] < k)
            {
                prev++;

                // If we reached next block or end of 
                // array, element is not present.
                if (prev == min(index, n))
                {
                    return -1;
                }
            }

            // Found
            if (arr[prev] == k)
            {
                return prev;
            }

            return -1;
        }

    };
} // namespace JumpSearch