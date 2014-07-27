#include <iostream>
#include <string>
#include <set>

using namespace std;
set<string> words;

bool isWord(string &w) {
    return words.find(w) != words.end();
}

int dfs(string &w, int n) {
    if (w.size() == 1)  {
        return n;
    }
    int max = 0;
    for (int i = 0; i < w.size(); i++) {
        char c = w[i];
        w.erase(i,1);
        if (isWord(w)) {
            int m = dfs(w, n+1);
            if (m > max) max = m;
        }
        w.insert(i,1,c);
    }
    return max;
}

int main() {
    words.insert("restate");
    words.insert("estate");
    words.insert("state");
    words.insert("stat");
    words.insert("sat");
    words.insert("at");
    words.insert("a");

    string w = "restate";
    cout << dfs(w,1) << endl;

    return 0;
}
