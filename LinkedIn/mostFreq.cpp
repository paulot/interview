#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <set>
#include <utility>

using namespace std;
ifstream fin ("test.in");

struct classcomp {
      bool operator() (const pair<string,int>& lhs, const pair<string,int>& rhs) const
            {return lhs.second>rhs.second;}
};

void getCount() {
    map <string, int> count;
    string in;
    while (fin.good()) {
        fin >> in;
        if (count.find(in) == count.end())
            count[in] = 1;
        else
            count[in]++;
    }
    count[in]--;

    set<pair<string,int>, classcomp> heap;

    for (map <string, int>::iterator i = count.begin(); i != count.end(); i++)
        heap.insert(make_pair(i->first, i->second));
    int c = 0;
    for (set<pair<string,int>, classcomp>::iterator i = heap.begin(); c < 100 and i != heap.end(); c++, i++)
        cout << i->first << " " << i->second << endl;
}

int main() {
    getCount();

    return 0;
}
