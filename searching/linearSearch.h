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
                    return i + 1;
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
                    return left + 1;
                }

                if (arr[right] == k)
                {
                    return right + 1;
                }

                left++;
                right--;
            }

            return -1;
        }
    };

    // { Driver Code Starts.

    // int main() {
    //     int t;
    //     cin >> t;
    //     while (t--) {
    //         int n, i, k;
    //         cin >> n >> k;
    //         int *a = new int[n];
    //         for (i = 0; i < n; i++) {
    //             cin >> a[i];
    //         }
    //         Solution ob;
    //         auto ans = ob.search(a, n, k);
    //         cout << ans << "\n";
    //     }
    //     return 0;
    // }

    // } Driver Code Ends
}; // namespace LinearSearch

#endif