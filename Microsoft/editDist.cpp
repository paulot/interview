// Write a program to find if a string a a k-palindrome
//

#include <iostream>
#include <string>

using namespace std;

int min(int a, int b, int c) {
    if (a < b)
        if (a < c)
            return a;
        else return (c < b) ? c : b;
    else
        if (b < c)
            return b;
        else return (a < c) ? a : c;
}

int laveshteinDist(string &first, string &second) {
    if (first == second)
        return 0;
    if (first.size() == 0)
        return second.size();
    if (second.size() == 0)
        return first.size();

    int v0[first.size() + 1];
    int v1[first.size() + 1];

    // Populate v0
    for (int i = 0; i <= first.size(); i++)
        v0[i] = i;

    for (int i = 0; i < second.size(); i++) {
        
        v1[0] = v0[0] + 1;
        int c;
        for (int j = 0; j < first.size(); j++) {
            c = (first[j] == second[i]) ? 0 : 1; 
            v1[j+1] = min(v1[j] + 1, v0[j]+c, v0[j+1] + 1);
        }
        for (int j = 0; j <= first.size(); j++) {
            cout << v1[j] << " ";
            v0[j] = v1[j];
        }
        cout << endl;
    }
    return v1[first.size()];
}

void flip(string &str) {
    int t;
    for (int i = 0; i < str.size()/2; i++) {
        t = str[i];
        str[i] = str[str.size() - i - 1];
        str[str.size() - i - 1] = t;
    }
}

int main() {
    string f = "paulo";
    string s = "potato";
    cout << laveshteinDist(s, f) << endl;

    return 0;
}
