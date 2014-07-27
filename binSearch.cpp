// Design a binary search algorithm

#include <iostream>

using namespace std;

int search(int *arr, int item, int n) {
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

int main() {
    int bla[] = { 1,2,3,4,5,6,7,8,9 };
    cout << "1 is at " << search(bla, 1, 9) << endl;
    cout << "2 is at " << search(bla, 2, 9) << endl;
    cout << "3 is at " << search(bla, 3, 9) << endl;
    cout << "4 is at " << search(bla, 4, 9) << endl;
    cout << "5 is at " << search(bla, 5, 9) << endl;
    cout << "6 is at " << search(bla, 6, 9) << endl;
    cout << "7 is at " << search(bla, 7, 9) << endl;
    cout << "8 is at " << search(bla, 8, 9) << endl;
    cout << "9 is at " << search(bla, 9, 9) << endl;

    int blu[1000];
    for (int i = 0; i < 1000; i++)
        blu[i] = i;

    cout << "444 is at " << search(blu, 444, 1000) << endl;
    cout << "598 is at " << search(blu, 598, 1000) << endl;
    cout << "623 is at " << search(blu, 623, 1000) << endl;
    cout << "10 is at " << search(blu, 10, 1000) << endl;

    cout << "0 is at " << search(bla, 0, 9) << endl;
    cout << "10 is at " << search(bla, 10, 9) << endl;
}
