// Given a sorted and shifted array find an element

#include <iostream>

using namespace std;

int bunnyJump(int arr[], int n, int find) {
    
    int i = 0, left = 0, right = n-1;
    int last = arr[0];
    while (i >= left and i <= right and left < right) {
        // cout <<  i << endl;
        if (arr[i] == find)
            return i;
        if (arr[left] == find)
            return left;
        if (arr[right] == find)
            return right;

        if (find < last and last <= arr[i]) {
            last = arr[i];
            left = i;
            i += (right - i)/2;
            right--;
            continue;
        }
        if (arr[i] < find) {
            last = arr[i];
            left = i;
            i += (right - i)/2;
            right--;
            continue;
        }
        if (arr[i] > find) {
            last = arr[i];
            right = i;
            i -= (i - left)/2;
            left++;
            continue;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 1,2,3,4,5,6,7,8,9 };
    int n = 9;
    cout << bunnyJump(arr, n, 2) << endl;
    return 0;
}
