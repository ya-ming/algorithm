#ifndef FIND_THE_MISSING_NUMBER
#define FIND_THE_MISSING_NUMBER

// You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in the list.
// One of the integers is missing in the list. Write an efficient code to find the missing integer.


// Method 1: This method uses the technique of the summation formula. 

// Approach: The length of the array is n-1. So the sum of all n elements,
//    i.e sum of numbers from 1 to n can be calculated using the formula n*(n+1)/2.
//    Now find the sum of all the elements in the array and subtract it from the sum of first n natural numbers,
//    it will be the value of the missing element.
// Algorithm:
// Calculate the sum of first n natural numbers as sumtotal= n*(n+1)/2
// Create a variable sum to store the sum of array elements.
// Traverse the array from start to end.
// Update the value of sum as sum = sum + array[i]
// Print the missing number as sumtotal - sum
int findTheMissingNumber(int a[], int n)
{
    int expectedSum = n * (n + 1) / 2;

    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += a[i];
    }

    return expectedSum - sum;
}

// Approach: The approach remains the same but there can be overflow if n is large.
//    In order to avoid integer overflow, pick one number from known numbers and subtract one number from given numbers.
//    This way there won’t have Integer Overflow ever.
// Algorithm: 
// Create a variable sum = 1 to which will store the missing number and a counter c = 2.
// Traverse the array from start to end.
// Update the value of sum as sum = sum - array[i] + c and update c as c++.
// Print the missing number as a sum.
int findTheMissingNumberPreventOverflow(int a[], int n)
{
    int sum = 1;

    for (int i = 2; i <= n + 1; i++)
    {
        sum += i;
        sum -= a[i - 2];
    }

    return sum;
}

#endif