
#include <iostream>

using namespace std;

int bs(int arr[], int n, int k, bool isLow) {
    int h = n-1, l = 0, m = (h + l)/2;
    while (h >= l) {
        cout << l << " " << m << " " << h << endl;
        if (isLow) {
            if (arr[l] == k) return l;
            if (arr[m] == k) {
                h = m, m = (h + l)/2;
            }
            l++;
            m++;
        } else { 
            if (arr[h] == k) return h;
            if (arr[m] == k)  {
                l = m, m = (h + l)/2;
            }
            h--;
            m--;
        }
        if (arr[m] < k) {
            l = m, m = (h + l)/2;
        }
        else if (arr[m] > k) {
            h = m, m = (h + l)/2;
        }
    }
    return -1;
}

int main() {
    // int arr[] = {0,0,2,3,3,3,3,4,7,7,9};
    int arr[] = {3,3,3,3,3,3,3,3,3,3,3};
    cout << "Start " << bs(arr, 11, 3, true) << endl;
    cout << "End " << bs(arr, 11, 3, false) << endl;
}
