#include <gtest/gtest.h>

#include "findTheMissingNumber.h"

TEST(FindTheMissingNumber, basic)
{
    int arr[] = {1, 2, 4, 6, 3, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]); 

    EXPECT_EQ(5, findTheMissingNumber(arr, n));
}

TEST(FindTheMissingNumber, overflow)
{
    int arr[] = {1, 2, 4, 6, 3, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]); 

    EXPECT_EQ(5, findTheMissingNumberPreventOverflow(arr, n));
}