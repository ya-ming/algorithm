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

        int binarySearchLessComparison(int arr[], int l, int r, int k)
        {
            int m;
            while (r - l > 1)
            {
                m = l + (r - l) / 2;

                if (arr[m] <= k)
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }

            if (arr[l] == k)
                return l;
            if (arr[r] == k)
                return r;

            return -1;
        }

        // largest value <= key
        // Invariant: A[l] <= key and A[r] > key
        // Boundary: |r - l| = 1
        // Input: A[l .... r-1]
        // Precondition: A[l] <= key <= A[r]
        int binarySearchFindFloor(int arr[], int l, int r, int k)
        {
            if (k < arr[0])
                return -1;

            int m;
            while (r - l > 1)
            {
                m = l + (r - l) / 2;

                if (arr[m] <= k)
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }

            return arr[l];
        }

        // Given a sorted array with possible duplicate elements. Find number of occurrences of input 'key' in log N time.
        // The idea here is finding left and right most occurrences of key in the array using binary search.
        // We can modify floor function to trace right most occurrence and left most occurrence.

        // Input: Indices Range [l ... r)
        // Invariant: A[l] <= key and A[r] > key
        // 1,2,3,4,5,5,5,6,7,8,9, return l = 6
        int getRightPosition(int arr[], int l, int r, int k)
        {
            int m;
            while (r - l > 1)
            {
                m = l + (r - l) / 2;
                if (arr[m] <= k)
                    l = m;
                else
                    r = m;
            }

            return l;
        }

        // Input: Indices Range (l ... r]
        // Invariant: A[r] >= key and A[l] > key
        // 1,2,3,4,5,5,5,6,7,8,9, return r = 4
        int getLeftPosition(int arr[], int l, int r, int k)
        {
            int m;
            while (r - l > 1)
            {
                m = l + (r - l) / 2;
                if (arr[m] >= k)
                    r = m;
                else
                    l = m;
            }

            return r;
        }

        int binarySearchFindNumberOfOccurrences(int arr[], int l, int r, int k)
        {
            // Observe boundary conditions 
            int left = getLeftPosition(arr, -1, r - 1, k);
            int right = getRightPosition(arr, 0, r, k);

            // What if the element doesn't exists in the array?
            // The checks helps to trace that element exists
            return (arr[left] == k && k == arr[right]) ? (right - left + 1) : 0;
        }

        // We converge the search space till l and r points single element.
        // If the middle location falls in the first pulse, the condition A[m] < A[r] doesn't satisfy,
        // we converge our search space to A[m+1 ... r]. If the middle location falls in the second pulse,
        // the condition A[m] < A[r] satisfied, we converge our search space to A[1 ... m].
        // At every iteration we check for search space size, if it is 1, we are done.
        // l                  r
        // 6 7 8 9 10 1 2 3 4 5
        // <---1st---><--2nd-->
        //     m
        //                  m
        int binarySearchIndexOfMinimumRotatedArray(int arr[], int l, int r)
        {
            int m;

            // Precondition: A[l] > A[r] 
            if (arr[l] <= arr[r])
                return l;
            
            while (l <= r)
            {
                // Termination condition (l will eventually falls on r, and r always 
                // point minimum possible value) 
                if (l == r)
                    return l;
                
                // 'm' can fall in first pulse, 
                // second pulse or exactly in the middle
                m = l + (r - l) / 2;

                if (arr[m] > arr[r])
                    l = m + 1;
                else if (arr[m] < arr[r])
                    r = m; 
            }
            return -1;
        }
    };
} // namespace BinarySearch

#endif