#include <iostream>
#include <string>

using namespace std;

void encode(string &s, string &ret) {
    for (int i = 1; i <= s.size(); i++) {
        int c = 1;
        while (i < s.size() and s[i] == s[i-1]) c++, i++;
        ret += s[i-1];
        ret += c + '0';
    }
}

int main() {
    string s = "abbaadddddc";
    string ret = "";
    encode(s, ret);
    cout << ret << endl;;
}
