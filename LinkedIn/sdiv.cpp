#include <iostream>

using namespace std;

void subsets(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = i; j < n; j++) {
            s += arr[j];
            if (s % 7 == 0) cout << i << " " << j << endl;
        }
    }
}
