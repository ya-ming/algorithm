#include <gtest/gtest.h>

#include "search.h"

namespace Search
{

TEST(substringSearch, exist)
{
    Solution ob;

    char txt[] = "THIS IS A TEST TEXT";
    char pat[] = "TEST";
    auto ans = ob.substringSearch(txt, pat);
    EXPECT_EQ(true, ans);
}

TEST(substringSearch, notExist)
{
    Solution ob;

    char txt[] = "THIS IS A TEST TEXT";
    char pat[] = "TET";
    auto ans = ob.substringSearch(txt, pat);
    EXPECT_EQ(false, ans);
}

TEST(unboundedBinarySearch, basic)
{
    Solution ob;
    auto ans = ob.findFirstPositive();
    EXPECT_EQ(12, ans);
}

}