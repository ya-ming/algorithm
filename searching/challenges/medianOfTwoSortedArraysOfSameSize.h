#ifndef MEDIAN_OF_TWO_SORTED_ARRAYS_OF_SAME_SIZE
#define MEDIAN_OF_TWO_SORTED_ARRAYS_OF_SAME_SIZE


// Use the merge procedure of merge sort.
// Keep track of count while comparing elements of two arrays.
// If count becomes n(For 2n elements), we have reached the median.
// Take the average of the elements at indexes n-1 and n in the merged array. See the below implementation. 
int medianOfTwoSortedArraysOfSameSize(int arr1[], int arr2[], int n)
{
    int i = 0;
    int index1 = 0;
    int index2 = 0;
    int x = 0;
    while (i < n)
    {
        if (arr1[index1] <= arr2[index2])
        {
            x = arr1[index1];
            index1++;
        }
        else if (arr1[index1] > arr2[index2])
        {
            x = arr2[index2];
            index2++;
        }
        i++;
    }

    int y = arr1[index1] <= arr2[index2] ? arr1[index1] : arr2[index2];
    return (x + y) / 2;
}

#endif