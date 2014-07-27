#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

char num[20];

bool isOctPal(unsigned int n) {
    int s = sprintf(num, "%o", n);
    for (int i = 0; i < s/2; i++)
        if (num[i] != num[s-i-1]) return false;
    printf("%d %o\n", n, n);
    return true;
}

int main() {
    int max = 21474;
    for (int n = 0; n < max; n++) {
        int number = n, rem = 0, reverse = 0, pdrome, no_digits = 1;
        while (number != 0)
            reverse = reverse * 10 + number % 10, number /= 10 , no_digits *= 10;
        pdrome = n <= 9 ? n : (no_digits / 10) * n + reverse % (no_digits / 10);
        isOctPal(pdrome);
    }
    return 0;
}
