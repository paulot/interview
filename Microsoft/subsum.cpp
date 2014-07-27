// A Dynamic Programming solution for subset sum problem
//    1   1   1   1   1   1   1
//    0   0   0   0   0   0   0
//    0   0   0   0   0   0   1
//    0   1   1   1   1   1   1
//    0   0   0   1   1   1   1
//    0   0   0   0   0   1   1
//    0   0   0   0   0   0   1
//    0   0   0   1   1   1   1
//    0   0   0   0   0   1   1
//    0   0   0   0   0   1   1
//
#include <iostream>
#include <cstring>

using namespace std;

bool isSubsum(int arr[], int n, int sum) {
    if (sum == 0) return true;
    if (n == 0) return false;

    bool subsum[sum+1][n+1];
    // memset(subsum, 0, sizeof(bool) * sum+1 * n+1);
    for (int i = 0; i <= sum; i++)
        for (int j = 0; j <= n; j++)
            subsum[i][j] = false;



    for (int i = 0; i <= n; i++)
        subsum[0][i] = true;

    for (int i = 1; i <= sum; i++) {

        for (int j = 1; j <= n; j++) {
            cout << "i: " << i << " j: " << j << " subsum " <<  subsum[i][j] << " arr: " << arr[j-1] << endl;
            if (i == arr[j-1]) subsum[i][j] = true;
            else
                subsum[i][j] = (i > arr[j-1]) ? subsum[i][j-1] or subsum[i-arr[j-1]][j-1]
                    : subsum[i][j-1];
            cout << "i: " << i << " j: " << j << " subsum " <<  subsum[i][j] << " arr: " << arr[j-1] << endl;
        }
    }

    for (int i = 0; i <= sum; i++) {
        for (int j = 0; j <= n; j++)
            cout << subsum[i][j] << " ";
        cout << endl;
    }


    return subsum[sum][n];
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set)/sizeof(set[0]);
    if (isSubsum(set, n, sum) == true)
        cout << "Found a subset with given sum" << endl;
    else
        cout << "No subset with given sum" << endl;
    return 0;
}























































/*
#include <stdio.h>
// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
    //  with sum equal to i
    bool subset[sum+1][n+1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[0][i] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
        subset[i][0] = false;

    // Fill the subset table in botton up manner
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            subset[i][j] = subset[i][j-1];
            if (i >= set[j-1])
                subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
        }
    }

    // uncomment this code to print table
    for (int i = 0; i <= sum; i++)
    {
        for (int j = 0; j <= n; j++)
            printf ("%4d", subset[i][j]);
        printf("\n");
    }

    return subset[sum][n];
}

// Driver program to test above function
int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set)/sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;
}
*/
