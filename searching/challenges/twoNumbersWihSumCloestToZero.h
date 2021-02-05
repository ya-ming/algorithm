#ifndef TWO_NUMBERS_WITH_SUM_CLOSE_TO_ZERO
#define TWO_NUMBERS_WITH_SUM_CLOSE_TO_ZERO

#include <algorithm>

/* FOLLOWING FUNCTIONS ARE ONLY FOR 
   SORTING PURPOSE */
void exchange(int *a, int *b) 
{ 
    int temp; 
    temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
int partition(int arr[], int si, int ei) 
{ 
    int x = arr[ei]; 
    int i = (si - 1); 
    int j; 
     
    for (j = si; j <= ei - 1; j++) 
    { 
        if(arr[j] <= x) 
        { 
            i++; 
            exchange(&arr[i], &arr[j]); 
        } 
    } 
    exchange (&arr[i + 1], &arr[ei]); 
    return (i + 1); 
} 
 
/* Implementation of Quick Sort 
    arr[] --> Array to be sorted 
    si --> Starting index 
    ei --> Ending index 
*/
void quickSort(int arr[], int si, int ei) 
{ 
    int pi; /* Partitioning index */
    if(si < ei) 
    { 
        pi = partition(arr, si, ei); 
        quickSort(arr, si, pi - 1); 
        quickSort(arr, pi + 1, ei); 
    } 
} 


// 1) Sort all the elements of the input array. 
// 2) Use two index variables l and r to traverse from left and right ends respectively. Initialize l as 0 and r as n-1. 
// 3) sum = a[l] + a[r] 
// 4) If sum is -ve, then l++ 
// 5) If sum is +ve, then r--
// 6) Keep track of abs min sum. 
// 7) Repeat steps 3, 4, 5 and 6 while l < r
void twoNumbersWihSumCloestToZero(int arr[], int n, int &x, int &y)
{
    if (n < 2)
        return;

    int l = 0, r = n - 1;
    quickSort(arr, l, r);

    int sum, min_sum = INT_MAX;
    x = l, y = r;

    while (l < r)
    {
        sum = arr[l] + arr[r];
        if (abs(sum) < abs(min_sum))
        {
            min_sum = sum;
            x = l;
            y = r;
        }
        // if having sum 1 and -1, make sure return 1 instead of -1
        // else if (abs(sum) == abs(min_sum))
        // {
        //     if (sum > 0)
        //     {
        //         min_sum = sum;
        //         x = l;
        //         y = r;
        //     }
        // }

        if (sum < 0)
            l++;
        else
            r--;
    }
}
#endif