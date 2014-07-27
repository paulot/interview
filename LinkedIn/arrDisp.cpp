#include <iostream>

using namespace std;

void dispArr(int arr[], int n, int c) {
    int nr = ((n%c) == 0) ? n/c : n/c + 1;
    int nlast = (n % c == 0) ? c : n%c;
    for (int r = 0; r < nr; r++) {
        int nc = (r < nr-1) ? c : (n%c == 0) ? c : n%c;
        int inc = nr, ind = r;
        for (int i = 0; i < nc; i++) {
            cout << arr[ind] << " ";
            inc = (i < nlast) ? inc : inc - 1;
            ind += inc;
        }
        cout << endl;
    }
}

int main() { 
    int arr[] = { 1,2,3,4,5,6,7,8,9 };
    dispArr(arr, 8, 3);
    return 0;
}
