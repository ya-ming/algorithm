#include <gtest/gtest.h>

#include "binarySearch.h"

namespace BinarySearch
{

TEST(binarySearch, basic)
{
    Solution ob;

    int n = 5, k = 6;
    int a[5] = {1, 2, 3, 4, 6};
    auto ans = ob.searchInSorted(a, n, k);
    EXPECT_EQ(5, ans);
}

TEST(binarySearch, basic0)
{
    Solution ob;

    int n = 1, k = 16;
    int a[1] = {16};
    auto ans = ob.searchInSorted(a, n, k);
    EXPECT_EQ(1, ans);
}

TEST(binarySearch, basic1)
{
    Solution ob;

    int n = 5, k = 20;
    int a[5] = {1, 2, 3, 4, 6};
    auto ans = ob.searchInSorted(a, n, k);
    EXPECT_EQ(-1, ans);
}

TEST(binarySearch, basic2)
{
    Solution ob;

    int n = 5, k = 1;
    int a[5] = {1, 2, 3, 4, 6};
    auto ans = ob.searchInSorted(a, n, k);
    EXPECT_EQ(1, ans);
}

}