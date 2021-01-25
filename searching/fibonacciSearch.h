#ifndef _FIBONACCI_SEARCH_
#define _FIBONACCI_SEARCH_

#include <iostream>
#include <algorithm>

using namespace std;

namespace FibonacciSearch
{
    /*
        Fibonacci Search is a comparison-based technique that uses Fibonacci numbers to search an element in a sorted array.

        Similarities with Binary Search:
            Works for sorted arrays
            A Divide and Conquer Algorithm.
            Has Log n time complexity.

        Differences with Binary Search:
            Fibonacci Search divides given array in unequal parts
            Binary Search uses division operator to divide range. Fibonacci Search doesn’t use /, 
            but uses + and -. The division operator may be costly on some CPUs.
            Fibonacci Search examines relatively closer elements in subsequent steps. 
            So when input array is big that cannot fit in CPU cache or even in RAM, Fibonacci Search can be useful.
    */
    class Solution
    {
    public:
        int fibonacciSearch(int arr[], int n, int x)
        {
            // initialize fibonacci numbers
            int fibMm2 = 0; // (m-2)'th Fibonacci number
            int fibMm1 = 1; // (m-1)'th Fibonacci number
            int fibM = fibMm2 + fibMm1;

            // fibM is going to store the smallest Fibonacci 
            //     Number greater than or equal to n
            while (fibM < n)
            {
                fibMm2 = fibMm1;
                fibMm1 = fibM;
                fibM = fibMm2 + fibMm1;
            }

            // marks the eliminated range from front
            int offset = -1;

            // while there are elements to be inspected. Note that 
            //     we compare arr[fibMm2] with x. When fibM becomes 1, 
            //     fibMm2 becomes 0
            while (fibM > 1)
            {
                // Check if fibMm2 is a valid location
                int i = min(offset + fibMm2, n - 1);

                // If x is greater than the value at index fibMm2, 
                //         cut the subarray array from offset to i
                if (arr[i] < x)
                {
                    fibM = fibMm1;
                    fibMm1 = fibMm2;
                    fibMm2 = fibM - fibMm2;
                    offset = i;
                }
                // If x is greater than the value at index fibMm2, 
                //         cut the subarray after i+1
                else if (arr[i] > x)
                {
                    fibM = fibMm2;
                    fibMm1 = fibMm1 - fibMm2;
                    fibMm2 = fibM - fibMm1;
                }
                // element found. return index
                else
                {
                    return i;
                }
            }

            // comparing the last element with x
            if (fibMm1 && arr[offset + 1] == x)
                return offset + 1;

            // element not found. return -1
            return -1;
        }
    };
} // namespace FibonacciSearch

#endif