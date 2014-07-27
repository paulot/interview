// Count number of bits
#include <iostream>
#include <limits.h>

using namespace std;

int nBits(int n) {
    int c = 0;
    while (n != 0) {
        c++;
        n &= n-1;
    }
    return c;
}

int NumberOfSetBits(int i)
{
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main() {
    for (int i = 0; i < 1000; i++)
        if (nBits(i) != NumberOfSetBits(i))
            cout << "Error at " << i << endl;

    return 0;
}
