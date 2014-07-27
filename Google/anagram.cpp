#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string &a, string &b) {
    int c[26] = { 0 };
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == ' ') continue;
        c[a[i]-'a']++;
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == ' ') continue;
        c[b[i]-'a']--;
    }
    for (int i = 0; i < 26; i++)
        if (c[i] != 0) return false;
    return true;
}

int main() {
    string a = "cofiers", b = "fir cones";
    cout << isAnagram(a,b) << endl;

    return 0;
}
