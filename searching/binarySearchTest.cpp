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
    EXPECT_EQ(4, ans);
}

TEST(binarySearch, basic0)
{
    Solution ob;

    int n = 1, k = 16;
    int a[1] = {16};
    auto ans = ob.searchInSorted(a, n, k);
    EXPECT_EQ(0, ans);
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
    EXPECT_EQ(0, ans);
}

TEST(binarySearch, recursive)
{
    Solution ob;

    int n = 5, k = 6;
    int a[5] = {1, 2, 3, 4, 6};
    auto ans = ob.binarySearch(a, 0, n - 1, k);
    EXPECT_EQ(4, ans);
}

TEST(binarySearch, recursive1)
{
    Solution ob;

    int n = 5, k = 2;
    int a[5] = {1, 2, 3, 4, 6};
    auto ans = ob.binarySearch(a, 0, n - 1, k);
    EXPECT_EQ(1, ans);
}

TEST(binarySearch, lessComparison)
{
    Solution ob;

    int n = 5, k = 6;
    int a[5] = {1, 2, 3, 4, 6};
    auto ans = ob.binarySearchLessComparison(a, 0, n - 1, k);
    EXPECT_EQ(4, ans);
}

TEST(binarySearch, findFloor)
{
    Solution ob;

    int n = 8, k = 7;
    int a[8] = {-1, 2, 3, 5, 6, 8, 9, 10};
    auto ans = ob.binarySearchFindFloor(a, 0, n - 1, k);
    EXPECT_EQ(6, ans);
}

TEST(binarySearch, findOccurannce)
{
    Solution ob;

    int n = 12, k = 5;
    int a[12] = {1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9, 10};
    auto ans = ob.binarySearchFindNumberOfOccurrences(a, 0, n - 1, k);
    EXPECT_EQ(3, ans);
}

TEST(binarySearch, findOccurannce1)
{
    Solution ob;

    int n = 12, k = 1;
    int a[12] = {1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9, 10};
    auto ans = ob.binarySearchFindNumberOfOccurrences(a, 0, n - 1, k);
    EXPECT_EQ(1, ans);
}

TEST(binarySearch, findOccurannceDoesntExist)
{
    Solution ob;

    int n = 12, k = -1;
    int a[12] = {1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9, 10};
    auto ans = ob.binarySearchFindNumberOfOccurrences(a, 0, n - 1, k);
    EXPECT_EQ(0, ans);
}

TEST(binarySearch, findIndexOfMinimumRotatedArray)
{
    Solution ob;

    int n = 10;
    int a[10] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    auto ans = ob.binarySearchIndexOfMinimumRotatedArray(a, 0, n - 1);
    EXPECT_EQ(5, ans);
}

}