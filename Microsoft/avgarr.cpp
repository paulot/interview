// Given an array of size n, divide the array in two arrays of size n/2 
// such that they average is the same

#include <iostream>
#include <vector>

bool naiveSubsetSum(int arr[], int n, int sum) {
    if (sum == 0) return true;
    if (n == 0) return false;
    if (arr[n-1] > sum) return naiveSubsetSum(arr, n-1, sum);
    return naiveSubsetSum(arr, n-1, sum-arr[n-1]) or 
        naiveSubsetSum(arr, n-1, sum);
}


