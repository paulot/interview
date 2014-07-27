#include <iostream>

using namespace std;

int rotBs(int arr[], int n, int key) {
    int low = 0, hi = n-1;
    while (low <= hi) {
        int mid = (hi+low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] >= arr[low]) {
            // bot is sort
            if (arr[low] <= key and arr[mid] > key)
                hi = mid-1;
            else
                low = mid+1;
        } else {
            if (arr[mid] < key and arr[hi] >= key)
                low = mid+1;
            else
                hi = mid-1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5,6,7,8,1,2,3};
    cout << rotBs(arr, 7, 3) << endl;
    return 0;
}
