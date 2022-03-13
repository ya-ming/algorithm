#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cassert>
#include "../utility/utility.h"

using namespace std;

namespace sort
{
    class Sort
    {
    private:
        
    public:
        // Proposition. Selection sort uses (N– 1) + (N– 2) + ... + 1 + 0 ~ N^2 / 2 compares
        // and N exchanges.
        void selectSort(vector<int> &a)
        {
            size_t N = a.size();
            for (int i = 0; i < N - 1; i++)
            {
                int min = i;
                for (int j = i + 1; j < N; j++)
                {
                    if (a[j] < a[min])
                    {
                        min = j;
                    }
                }

                swap(a[i], a[min]);
            }
        }

        void insertionSort(vector<int> &a, int lo, int hi)
        {
            for (int i = lo; i < hi + 1; i++)
            {
                for (int j = i; j > lo; j--)
                {
                    if (a[j] < a[j - 1])
                    {
                        swap(a[j], a[j - 1]);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        void shellSort(vector<int> &a)
        {
            size_t N = a.size();
            int h = 0;
            // 3x + 1
            while (h < N/3)
            {
                h = 3*h + 1;
            }

            while (h >= 1)
            {
                for (int i = h; i < N; i++)
                {
                    for (int j = i; j >= h; j -= h)
                    {
                        if (a[j] < a[j - h])
                        {
                            swap(a[j], a[j - h]);
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                h = h/3;
            }
        }

        void shuffle(vector<int> &a)
        {
            int N = a.size();
            random_device rd;
            mt19937 gen(rd());

            for (int i = 0; i < N; i++)
            {
                uniform_int_distribution<> distrib(0, i + 1);
                unsigned int r = distrib(gen);
                swap(a[i], a[r]);
            }
        }

        void merge(vector<int> &a, vector<int> &aux, int lo, int mid, int hi)
        {
            assert(isSorted(a, lo, mid));
            assert(isSorted(a, mid + 1, hi));

            int i = lo, j = mid + 1;
            for (int k = lo; k <= hi; k++)
            {
                aux[k] = a[k];
            }

            for (int k = i; k <= hi; k++)
            {
                if (i > mid)
                {
                    a[k] = aux[j++];
                }
                else if (j > hi)
                {
                    a[k] = aux[i++];
                }
                else if (aux[i] <= aux[j])
                {
                    a[k] = aux[i++];
                }
                else
                {
                    a[k] = aux[j++];
                }
            }

            assert(isSorted(a, lo, hi));
        }

        void mergeSort(vector<int> &a, vector<int> &aux, int lo, int hi)
        {
            // initial implementation
            // if (hi <= lo)
            //     return;
            // optimization: because Mergesort has too much overhead for tiny subarrays
            #define CUTOFF 7
            if (hi <= lo + CUTOFF - 1)
            {
                insertionSort(a, lo, hi);
                return;
            }

            int mid = lo + (hi - lo) /2;
            mergeSort(a, aux, lo, mid);
            mergeSort(a, aux, mid + 1, hi);

            // optimization: stop if already sorted
            if (a[mid + 1] >= a[mid])
                return;

            merge(a, aux, lo, mid, hi);
        }

        void bottomUpMergeSort(vector<int> &a)
        {
            int N = a.size();
            vector<int> aux(a.size());
            for (int sz = 1; sz < N; sz = sz + sz)
            {
                for (int lo = 0; lo < N - sz; lo += sz + sz)
                {
                    merge(a, aux, lo, lo + sz - 1, min(lo + sz + sz - 1, N - 1));
                }
            }
        }
    };
}