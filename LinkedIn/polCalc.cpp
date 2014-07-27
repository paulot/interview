#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>
#include <string>

#define calc(c) \
                cout << n << endl;                      \
                if (s.size() < 2) {                     \
                    cout << "Malformed expr" << endl;   \
                    return 0;                           \
                }                                       \
                n1 = s.top();                           \
                cout << "n1 " << n1 << endl;            \
                s.pop();                                \
                n2 = s.top();                           \
                cout << "n2 " << n2 << endl;            \
                s.pop();                                \
                s.push(n2 c n1);

using namespace std;
ifstream fin ("test.in");

int compute() {
    stack<int> s;
    string n;

    int n1, n2;
    while (fin.good()) {
        fin >> n;
        if (fin.good()) {
            switch (n[0]) {
                case '*':
                    calc(*);
                    break;
                case '/':
                    calc(/);
                    break;
                case '+':
                    calc(+)
                    break;
                case '-':
                    calc(-);
                    break;
                default:
                    s.push(atoi(n.c_str()));
                    break;
            }
        }
    }
    return s.top();
}

int main() {
    cout << compute() << endl;

    return 0;
}
