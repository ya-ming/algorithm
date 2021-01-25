#include <gtest/gtest.h>

#include "fibonacciSearch.h"

namespace FibonacciSearch
{

TEST(fibonacciSearch, basic)
{
    Solution ob;

    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 
                 85, 90, 100}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int x = 85;
    auto ans = ob.fibonacciSearch(arr, n, x);
    EXPECT_EQ(8, ans);
}

}