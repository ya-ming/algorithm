#include <gtest/gtest.h>

#include "exponentialSearch.h"

namespace ExponentialSearch
{

TEST(exponentialSearch, basic)
{
    Solution ob;

    int n = 5, k = 6;
    int a[5] = {1, 2, 3, 4, 6};
    auto ans = ob.exponentialSearch(a, n, k);
    EXPECT_EQ(5, ans);
}

TEST(exponentialSearch, basic1)
{
    Solution ob;

    int n = 5, k = 10;
    int a[5] = {1, 2, 3, 4, 6};
    auto ans = ob.exponentialSearch(a, n, k);
    EXPECT_EQ(-1, ans);
}

}