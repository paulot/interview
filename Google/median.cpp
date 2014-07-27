#include <iostream>
#include <cstdlib>

using namespace std;


int compare (const void * a, const void * b) {
      return ( *(int*)a - *(int*)b );
}

int median(int arr[], int n) {
    if (n <= 4) {
        qsort(arr, n, sizeof(int), compare);
        return arr[n/2];
    }
    int a[n/4+1];
    int i = 0, j = 0;
    for (i,j; i < n; j++, i += 4) {
        if (i + 4 < n)
            a[j] = median(arr+i, 4);
        else 
            a[j] = median(arr+i, n-i);
    }
    for (i = 0; i < j; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "j: " << j << endl;
    return median(a, j);
}

int main() {
    int arr[] = {2,5,7,8,2,3,4,5,6,4,5,6,7,8,98,9};
    int s = 16;
    cout << median(arr, s) << endl;
    qsort(arr, s, sizeof(int), compare);
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << arr[s/2] << endl;
}
