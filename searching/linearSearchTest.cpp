#include <gtest/gtest.h>

#include "linearSearch.h"

using namespace LinearSearch;

TEST(LinearSearch, basic) {
  Solution ob;
  
  int n = 5, k = 16;
  int a[5] = {9, 7, 2, 16, 4};
  auto ans = ob.search(a, n, k);
  EXPECT_EQ(4, ans);
}