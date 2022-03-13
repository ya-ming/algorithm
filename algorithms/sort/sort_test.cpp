#include <gtest/gtest.h>
#include <fstream>
#include "sort.h"
#include "../utility/stopWatch.h"
#include "../utility/utility.h"

namespace sort
{

TEST(sort, selection_sort)
{
    Sort sort;

    vector<int> a{2, 10, 5, 3, 8, 4, 7, 9, 6};
    sort.selectSort(a);

    vector<int> exp{2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(exp, a);
}

TEST(sort, insertion_sort)
{
    Sort sort;

    vector<int> a{2, 10, 5, 3, 8, 4, 7, 9, 6};
    sort.insertionSort(a, 0, a.size() - 1);

    vector<int> exp{2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(exp, a);
}

TEST(sort, shell_sort)
{
    Sort sort;

    vector<int> a;

    std::ifstream in("algorithms/inputs/1Kints.txt");
    int x;
    while (in >> x)
    {
        a.push_back(x);
    }

    StopWatch stopWatch;
    sort.shellSort(a);
    stopWatch.elapsedTime();
}

TEST(sort, knuth_shuffle)
{
    Sort sort;

    vector<int> a{2, 3, 4, 5, 6, 7, 8, 9, 10};
    sort.shuffle(a);
}

TEST(sort, merge)
{
    Sort sort;

    vector<int> a{6, 7, 8, 9, 2, 3, 4, 5};
    vector<int> aux(a.size());

    sort.merge(a, aux, 0, 3, 7);
}

TEST(sort, merge_sort)
{
    Sort sort;

    vector<int> a{25, 24, 13, 23, 22, 12, 21, 20, 11, 26, 3, 28, 6, 27, 7, 29, 1, 30, 15, 4, 17, 5, 16, 9, 18, 2, 20, 10, 19, 8};
    vector<int> aux(a.size());

    sort.mergeSort(a, aux, 0, a.size() - 1);

    EXPECT_TRUE(isSorted(a, 0, a.size() - 1));
}

}