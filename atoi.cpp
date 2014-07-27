#include <iostream>

#define retneg(neg, result) (neg) ? -1 * result : result

using namespace std;

int toDigit(char c) {
    return c - '0';
}

int atoi(char *string) {
    int c = string[0], d;
    bool negative = false;
    if (c == '-') {
        string++;
        negative = true;
    }
    int result = 0;
    while ((c = string++[0]) != '\0') {
        d = toDigit(c);
        if (d < 0 or d > 9)
            return retneg(negative, result);
        result = (result * 10) + d;
    }
    return retneg(negative, result);
}

int main() {
    cout << atoi((char *) "543") << endl;
    cout << atoi((char *) "233sa4") << endl;
    cout << atoi((char *) "") << endl;
    cout << atoi((char *) "iad443") << endl;
    cout << atoi((char *) "-443") << endl;
}
