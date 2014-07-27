#include <iostream>

using namespace std;

int intLog(unsigned int n) {
    int c = 0;
    while (n > 1) n >>= 1, c++;
    return c;
}

int main() {
    cout << intLog(16) << endl;
    return 0;
}
