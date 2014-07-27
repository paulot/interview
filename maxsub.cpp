#include <iostream>
#include <limits.h>

using namespace std;

int maxsubsum(int arr[], int n) {
    int max  = INT_MIN;
    int csum = max;

    for (int i = 0; i < n; i++) {
        if (csum < 0)
            csum = arr[i];
        else
            csum += arr[i];
        if (csum >= max)
            max = csum;
    }
    return max;
}

int main() {
    int nums[10] = { 3,6,8,-9,-4,3,8,10,-5,6 };

    cout << maxsubsum(nums, 10) << endl;
    return 0;
}
