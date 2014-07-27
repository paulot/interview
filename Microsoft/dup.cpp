#include <iostream>
#include <string>
#include <set>

using namespace std;

void rmDup(string &str) {
   set<char> s;
   for (int i = 0; i < str.size(); i++) {
       if (s.find(str[i]) == s.end()) {
           s.insert(str[i]);
       } else {
           str.erase(i,1);
       }
   }
}

int main() {
    string str = "amazon";
    rmDup(str);
    cout << str << endl;
    return 0;
}
