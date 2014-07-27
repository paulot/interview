#include <iostream>
#include <limits.h>

using namespace std;

int maxsub(int arr[], int n) {
    int max = 0, cmax = 0;
    for (int i = 0; i < n; i++) {
        cmax += arr[i];
        if (cmax < 0)
            cmax = 0;
        if (cmax > max)
            max = cmax;
    }
    return max;
}

int main() {
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxsub(arr, 9) << endl;
    return 0;
}
