#include <iostream>
#include <string>

using namespace std;

int atoi(string &s) {
    int n = 0, sig = s[0] == '-' ? -1 : 1;
    for (int i = sig == -1 ? 1 : 0; i < s.size(); i++) {
        if (s[i]-'0' >= 0 and s[i]-'0' <= 9) {
            n *= 10;
            n += s[i]-'0';
        } else 
            return n * sig;
    }
    return n;
}

int main() {
    string s = "-43op";
    cout << atoi(s) << endl;

    return 0;
}
