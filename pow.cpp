// Write pow(x,y) = x^y
#include <iostream>

using namespace::std;
/*
int pow(int x, int y) {
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    if (y % 2)
        return x * pow(x * x, (y - 1)/2);
    else
        return pow (x * x, y/2);
}
*/
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

int main() {
    cout << pow(2,2) << endl;
    cout << pow(3,2) << endl;
    cout << pow(4,2) << endl;
    cout << pow(6,2) << endl;
    cout << pow(2,9) << endl;

    return 0;
}
