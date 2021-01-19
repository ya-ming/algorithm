#include <gtest/gtest.h>

#include "jumpSearch.h"

namespace JumpSearch
{

TEST(jumpSearch, basic)
{
    Solution ob;

    int a[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 
                34, 55, 89, 144, 233, 377, 610};
    int n = sizeof(a)/sizeof(a[0]), k = 55;
    auto ans = ob.searchInSorted(a, n, k);
    EXPECT_EQ(10, ans);
}

}