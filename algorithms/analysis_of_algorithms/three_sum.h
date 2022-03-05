#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace analysis_of_algorithms
{
    class ThreeSum
    {
    private:
        
    public:
        // O(N^3)
        int bruteForce(vector<int> &a)
        {
            size_t N = a.size();
            int count = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = i + 1; j < N; j++)
                {
                    for (int k = j + 1; k < N; k++)
                    {
                        if (a[i] + a[j] + a[k] == 0)
                        {
                            count++;
                        }
                    }
                }
            }
            return count;
        }

        // O(N^2logN)
        int fast(vector<int> &a)
        {
            sort(a.begin(), a.end());
            size_t N = a.size();
            int count = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = i + 1; j < N; j++)
                {
                    // search for -(a[i] + a[j])
                    int k = binarySearch(a, -(a[i] + a[j]));
                    // if found k, only count only count if i < j < k to avoid double counting
                    if (k != -1 && j < k)
                    {
                        count++;
                    }
                }
            }
            return count;
        }

        int binarySearch(vector<int> &a, int key)
        {
            int lo = 0, hi = a.size() - 1;
            while (lo <= hi)
            {
                int mid = lo + (hi - lo)/2;
                if (key < a[mid])
                {
                    hi = mid - 1;
                }
                else if (key > a[mid])
                {
                    lo = mid + 1;
                }
                else
                {
                    return mid;
                }
            }
            return -1;
        }
    };
}