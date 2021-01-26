#include <gtest/gtest.h>

#include "linearSearch.h"

namespace LinearSearch
{

TEST(LinearSearch, basic)
{
    Solution ob;

    int n = 5, k = 16;
    int a[5] = {9, 7, 2, 16, 4};
    auto ans = ob.search(a, n, k);
    EXPECT_EQ(3, ans);
}

TEST(LinearSearch, improved)
{
    Solution ob;

    int n = 5, k = 16;
    int a[5] = {9, 7, 2, 16, 4};
    auto ans = ob.improvedSearch(a, n, k);
    EXPECT_EQ(3, ans);
}

TEST(LinearSearch, improved1)
{
    Solution ob;

    int n = 5, k = 20;
    int a[5] = {9, 7, 2, 16, 4};
    auto ans = ob.improvedSearch(a, n, k);
    EXPECT_EQ(-1, ans);
}

TEST(LinearSearch, recursive)
{
    Solution ob;

    int n = 5, k = 16;
    int a[5] = {9, 7, 2, 16, 4};
    auto ans = ob.recSearch(a, 0, n - 1, k);
    EXPECT_EQ(3, ans);
}

}