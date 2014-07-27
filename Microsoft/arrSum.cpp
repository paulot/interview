// Given two arrays, find all of the numbers in the arrays that sum to a given number

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int> &arr, int item, int n) {
    int pivot = n / 2;
    int end   = n - 1;
    int start = 0;


    while(start <= end) {
        if(arr[pivot] == item)
            return pivot;
        if(arr[start] == item)
            return start;
        if(arr[end] == item)
            return end;
        if(arr[pivot] > item) {
            // Item is on the smaller half
            start++;
            end = pivot - 1;
            pivot = (end + start) / 2;
        } else {
            // Item is on the bigger half
            end--;
            start = pivot + 1;
            pivot = (end + start) / 2;
        }
    }
    return -1;
}

void arrSum(vector<int> &farr, vector<int> &sarr, int n) {
    sort(farr.begin(), farr.end());

    for (int i = 0; i < sarr.size(); i++) {
        if (search(farr, n - sarr[i], farr.size()) != -1)
            cout << n - sarr[i] << " " << sarr[i] << endl;
    }
}

int main() {
    vector<int> farr;
    vector<int> sarr;
    for (int i = 1; i <= 30; i++)
        farr.push_back(i);
    sarr = farr;
    for (int i = 0; i < 50; i += 3) {
        cout << "//" << i << endl;
        arrSum(farr, sarr, i);
    }
    return 0;
}


