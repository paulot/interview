#include <iostream>
#include <string>


using namespace std;

void ReplaceStringInPlace(std::string& subject, const std::string& search,
        const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
}
int treeDepth(string &s) {
    int d = 0, os;
    string se = "(00)", r = "0";
    while (s[0] != '0') {
        os = s.size();
        ReplaceStringInPlace(s, se, r);
        d++;
        if (os == s.size()) return -1;
    }
    return d-1;
}

int main() {
    // string t = "((00)(0(0(00))))";
    string t = "(00)";
    cout << treeDepth(t) << endl;

    return 0;
}
