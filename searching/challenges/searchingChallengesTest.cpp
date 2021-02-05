#include <gtest/gtest.h>

#include "findTheMissingNumber.h"
#include "medianOfTwoSortedArraysOfSameSize.h"
#include "twoNumbersWihSumCloestToZero.h"

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

TEST(FindTheMissingNumber, missing4)
{
    int arr[] = {1,2,3,5};
    int n = sizeof(arr)/sizeof(arr[0]); 

    EXPECT_EQ(4, findTheMissingNumberPreventOverflow(arr, n));
}

TEST(FindTheMissingNumber, missing9)
{
    int arr[] = {1,2,3,4,5,6,7,8,10};
    int n = sizeof(arr)/sizeof(arr[0]); 

    EXPECT_EQ(9, findTheMissingNumberPreventOverflow(arr, n));
}

TEST(MedianOfTwoSortedArraysOfSameSize, basic)
{
    int arr1[] = {1, 12, 15, 26, 38};
    int arr2[] = {2, 13, 17, 30, 45};
    int n = sizeof(arr1)/sizeof(arr1[0]); 

    EXPECT_EQ(16, medianOfTwoSortedArraysOfSameSize(arr1, arr2, n));
}

TEST(TwoNumbersWihSumCloestToZero, basic)
{
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr)/sizeof(arr[0]); 

    int x = 0, y = 0;
    twoNumbersWihSumCloestToZero(arr, n, x, y);
    EXPECT_EQ(-80, arr[x]);
    EXPECT_EQ(85, arr[y]);
}