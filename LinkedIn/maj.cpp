// Find Majority Element

#include <iostream>

using namespace std;

int findCandidate(int arr[], int n) {
    int count = 0, ind = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[ind]) count++;
        else count--;
        if (count <= 0) ind = i, count = 0;
    }
    return ind;
}

bool isMaj(int arr[], int n, int ind) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == arr[ind]) count++;
    return count >= n/2;
}

int main() {
    int arr[] = {2, 2, 6, 7,8,9, 2,2,2};
    cout << isMaj(arr, 9, findCandidate(arr, 9)) << endl;

    return 0;
}
