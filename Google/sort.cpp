// Give you an array which has n integers,it has both positive 
// and negative integers.Now you need sort this array in a 
// special way.After that,the negative integers should in the
// front,and the positive integers should in the back.
// Also the relative position should not be changed. 
// eg. -1 1 3 -2 2 ans: -1 -2 1 3 2. 
// o(n)time complexity and o(1) space complexity is perfect.

#include <iostream>
#include <cstring>

using namespace std;

void swap (int arr[], int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void sort(int arr[], int n) {
    int nextNonNeg = 0;
    int i = 0;
    for (i, nextNonNeg; i < n; i++, nextNonNeg++)
        if (arr[i] > 0)
            break;

    for (i; i < n; i++) {
        if (arr[i] < 0) {
            int t = arr[i];
            memmove(&(arr[nextNonNeg + 1]), 
                    &(arr[nextNonNeg]), 
                    sizeof(int) * (i - nextNonNeg));
            // swap(arr, i, nextNonNeg);
            arr[nextNonNeg] = t;
            nextNonNeg++;
        }
    }
}
/*
void sort(int arr[], int n) {
    int dup[n];
    memcpy(dup, arr, sizeof(int) * n);

    int nextNonNeg = 0;
    int i = 0;
    for (i, nextNonNeg; i < n; i++, nextNonNeg++)
        if (arr[i] > 0)
            break;
    for (i; i < n; i++) {
        if (arr[i] < 0) {
            swap(arr, i, nextNonNeg);
            nextNonNeg++;
        }
    }

    int lastNeg = n-1;
    i = n-1;
    for (i, lastNeg; i >= 0; i--, lastNeg--)
        if (dup[i] < 0)
            break;
    for (i; i >= 0; i--) {
        if (dup[i] > 0) {
            swap(dup, i, lastNeg);
            lastNeg--;
        }
    }

    for (int i = 0; i < n; i++)
        if (arr[i] > 0)
            arr[i] = dup[i];
}
*/

int main() {
    int arr[] = { -1, 1, 3, -2, 2, -3, -88, -5, 55, -9 };
    int n = 10;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    sort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
