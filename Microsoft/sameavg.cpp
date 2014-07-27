// Given an array print true is there is such subarray of n/2 elements that 
// has the same average as the remaining n/2 elements

#include <iostream>

using namespace std;

bool hasAvg(int arr[], int n) {
    if (n == 0) return true;
    if (n%2) return false;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int halfSum = sum/2;
    bool subsum[halfSum + 1][n + 1];
    for (int i = 0; i <= halfSum; i++)
        for (int j = 0; j <= n; j++)
            subsum[i][j] = false;

    for (int i = 0; i <= n; i++)
        subsum[0][i] = true;

    for (int i = 1; i <= halfSum; i++) {
        for (int j = 1; j <= n; j++) {
            if (i > halfSum) return false;
            subsum[i][j] = (i >= arr[j-1]) ? subsum[i][j-1] or subsum[i - arr[j-1]][j-1] :
                subsum[i][j-1];
        }
    }
    if (subsum[halfSum][n]) {
        
    }
    return subsum[halfSum][n];
}

int main() {
    int arr[] = { 4,4,4,4,4,4,4,4,4,4,4,4 };
    cout << hasAvg(arr, 12) << endl;

    return 0;
}
