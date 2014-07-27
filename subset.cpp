// write a method to return all subsets of a set

#include <iostream>

using namespace std;

void printArr(int arr[], unsigned int toPrint) {
    if (toPrint == 0) {
        cout << "{}" << endl;
        return;
    }
    int printing = 0;
    while (toPrint != 0) {
        if (toPrint % 2) cout << arr[printing] << " ";
        printing++;
        toPrint >>= 1;
    }
    cout << endl;
}

int pow(int x, int y) {
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    int ret = 1;
    int ans = x;
    while (y > 0) {
        if (y % 2)
            ret *= ans;
        ans *= ans;
        y /= 2;
    }
    return ret;
}


void subsetChoose(int arr[], int n) {
    for (int i = 0; i < pow(2, n); i++)
        printArr(arr, i);
}

// -------------------------------------------------------------

void swap(int arr[], int s, int e) {
    int t = arr[s];
    arr[s] = arr[e];
    arr[e] = t;
}

int NumberOfSetBits(int i)
{
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

void permute(int arr[], int start, int end) {
    if (start >= end) {
        for (int i = 0; i < end; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    for (int i = start; i < end; i++) {
        swap(arr, start, i);
        permute(arr, start+1, end);
        swap(arr, start, i);
    }
}

void pickArr(int arr[], unsigned int toPick) {
    if (toPick == 0) {
        cout << "{}" << endl;
        return;
    }
    int size = NumberOfSetBits(toPick);
    int toWrite[size];
    int picking = 0, writing = 0;
    while (toPick  != 0) {
        if (toPick % 2) toWrite[writing++] = arr[picking];
        picking++;
        toPick >>= 1;
    }
    permute(toWrite, 0, size);
}

void subsetPick(int arr[], int n) {
    for (int i = 0; i < pow(2, n); i++)
        pickArr(arr, i);
}

int main() {
    int arr[] = { 1,2,3 };
    cout << "Arr choose n" << endl;
    subsetChoose(arr, 3);
    cout << "Arr pick n" << endl;
    subsetPick(arr, 3);

    return 0;
}
