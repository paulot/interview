#include <iostream>
#define swap(a,b) int t = src[a]; \
                  cout << "SWAP " << src[a] << " " << src[b] << endl; \
                  src[a] = src[b]; src[b] = t; \
                  srcmap[t] = b; srcmap[src[a]] = a; \

using namespace std;

int firstDiff(int src[], int tgt[], int n) {
    for (int i = 0; i < n; i++)
        if (src[i] != tgt[i]) return i;
    return -1;
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void findSteps(int src[], int tgt[], int n) {
    int srcmap[n];
    for (int i = 0; i < n; i++)
        srcmap[src[i]] = i;
    
    // change zero's position until it is on the right place
    // when on the right place checl tgt==src
    // if so, done
    // if not, swap zero with the first non correct int you found
    while (true) {
        if (src[srcmap[0]] == tgt[srcmap[0]]) {
            int f = firstDiff(src, tgt, n);
            if (f == -1) return;
            swap(srcmap[0], f);
        } else {
            swap(srcmap[0], srcmap[tgt[srcmap[0]]]);
        }
    }
    return;
}

int main() {
    int a[] = {1,0,2,3}, b[] = {0,2,3,1};
    findSteps(a,b,4);

    return 0;
}
