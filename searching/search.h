#ifndef _SEARCH_
#define _SEARCH_

#include <iostream>

using namespace std;

namespace Search
{
    class Solution
    {
    public:
        /* Recursive function to do substring search */
        bool exactMatch(char txt[], char pat[])
        {
            if (txt[0] == '\0' && pat[0] != '\0')
                return false;
            else if (pat[0] == '\0')
                return true;
            else if (txt[0] == pat[0])
                return exactMatch(txt + 1, pat + 1);

            return false;
        }

        bool substringSearch(char txt[], char pat[])
        {
            if (txt[0] == '\0')
                return false;
            // If current characters of pat and txt match
            if (txt[0] == pat[0])
            {
                if (exactMatch(txt + 1, pat + 1))
                    return true;
                else
                    return substringSearch(txt + 1, pat);
            }

            // If current characters of pat and txt don't match
            return substringSearch(txt + 1, pat);
        }
        /* End of Recursive function to do substring search */

        /* Unbounded Binary Search
         Find the point where a monotonically increasing function becomes positive first time */
        // int unboundedBinarySearch(int low, int high);

        // Let's take an example function  
        // as f(x) = x^2 - 10*x - 20 Note that 
        // f(x) can be any monotonocally increasing function  
        int f(int x) { return (x*x - 10*x - 20); }

        // Returns the value x where above 
        // function f() becomes positive  
        // first time.  
        int findFirstPositive()
        {
            // When first value itself is positive
            if (f(0) > 0)
                return 0;

            // Find 'high' for binary search by repeated doubling 
            int  i = 1;
            while (f(i) <= 0)
                i = i*2;
            
            // Call binary search
            return unboundedBinarySearch(i/2, i);
        }

        // Searches first positive value 
        // of f(i) where low <= i <= high 
        int unboundedBinarySearch(int low, int high)
        {
            // mid = (low + high)/2
            int mid = low + (high - low) / 2;

            // If f(mid) is greater than 0 and 
            // one of the following two  
            // conditions is true:  
            // a) mid is equal to low  
            // b) f(mid-1) is negative 
            if (f(mid) > 0 && (mid == low || f(mid - 1) <= 0))
                return mid;

            if (f(mid) <= 0)
                return unboundedBinarySearch(mid + 1, high);
            else if (f(mid) > 0)
                return unboundedBinarySearch(low, mid - 1);

            // Return -1 if there is no positive value in given range
            return -1;
        }

        /* End of Unbounded Binary Search */
    };
}; // namespace Search

#endif