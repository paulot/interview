// Swap with no temp

#include <iostream>

using namespace std;

int main() {
    int a = 9;
    int b = 3;

    cout << a << " " << b << endl;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << " " << b << endl;

    return 0;
}
