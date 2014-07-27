#include <iostream>

using namespace std;

int count(int n) {
    int c = 0, mc = 0;
    while (n) {
        switch(n%4) {
            case 0:
                c += 2;
                break;
            case 1:
                mc = (mc > c) ? mc : c;
                c = 1;
                break;
            case 2:
                c++;
                mc = (mc > c) ? mc : c;
                c = 0;
                break;
            case 3:
                mc = (mc > c) ? mc : c;
                c = 0;
                break;
        }
        n >>= 2;
    }
    return mc;
}

int main() {
    cout << count(133) << endl;
    return 0;
}
