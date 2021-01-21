#include <gtest/gtest.h>

#include "ternarySearch.h"

namespace TernarySearch
{

TEST(ternarySearch, basic)
{
    Solution ob;

    int n = 5, k = 6;
    int a[5] = {1, 2, 3, 4, 6};
    auto ans = ob.ternarySearch(a, 0, n, k);
    EXPECT_EQ(4, ans);
}

}