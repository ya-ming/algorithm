#include <gtest/gtest.h>

#include "findTheMissingNumber.h"
#include "medianOfTwoSortedArraysOfSameSize.h"
#include "twoNumbersWihSumCloestToZero.h"
#include "findTheSmallestAndsecondSmallestElementsInAnArray.h"
#include "findTheMiddleOfThreeNumbers.h"

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

TEST(findTheSmallestAndsecondSmallestElementsInAnArray, basic)
{
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr)/sizeof(arr[0]); 

    int s1, s2;
    findTheSmallestAndsecondSmallestElementsInAnArray(arr, n, s1, s2);
    EXPECT_EQ(-80, s1);
    EXPECT_EQ(-10, s2);
}

TEST(findTheSmallestAndsecondSmallestElementsInAnArray, basic2)
{
    int arr[] = {2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]); 

    int s1, s2;
    findTheSmallestAndsecondSmallestElementsInAnArray(arr, n, s1, s2);
    EXPECT_EQ(2, s1);
    EXPECT_EQ(3, s2);
}

TEST(findTheSmallestAndsecondSmallestElementsInAnArray, basic3)
{
    int arr[] = {1, 1, 1, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]); 

    int s1, s2;
    EXPECT_EQ(false, findTheSmallestAndsecondSmallestElementsInAnArray(arr, n, s1, s2));
}

TEST(findTheSmallestAndsecondSmallestElementsInAnArray, basic4)
{
    int arr[] = {859, 396, 30, 238, 236, 794, 819, 429, 144, 12, 929, 530, 777, 405, 444, 764, 614, 539, 607, 841, 905, 819};
    int n = sizeof(arr)/sizeof(arr[0]); 

    int s1, s2;
    EXPECT_EQ(true, findTheSmallestAndsecondSmallestElementsInAnArray(arr, n, s1, s2));
    EXPECT_EQ(12, s1);
    EXPECT_EQ(30, s2);
}

TEST(findTheMiddleOfThreeNumbers, basic)
{
    int A = 978, B = 518, C = 300;
    EXPECT_EQ(B, findTheMiddleOfThreeNumbers(A, B, C));

    A = 162;
    B = 934;
    C = 200;
    EXPECT_EQ(C, findTheMiddleOfThreeNumbers(A, B, C));
}