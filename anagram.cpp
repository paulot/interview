// Given two words this program shold check if the words 
// are anagrams of each other

#include <iostream>
#include <string>
#include <map>

using namespace::std;

bool isAnagram(string first, string second) {
    map<char, int> hash;
    int operations = 0;

    for (int i = 0; i < second.size(); i++) {
        if (second[i] == ' ') continue;
        if (hash.find(second[i]) == hash.end())
            hash[second[i]] = 1;
        else
            hash[second[i]] += 1;
        operations++;
    }
    for (int i = 0; i < first.size(); i++) {
        if (first[i] == ' ') continue;
        if (hash.find(first[i]) == hash.end())
            return false;
        else {
            hash[first[i]] -= 1;
            operations--;
            if (hash[first[i]] < 0 || operations < 0)
                return false;
        }
    }
    return operations == 0;
}

int main() {
    cout << isAnagram("secure", "rescue") << endl;
    cout << isAnagram("confiers", "fircones") << endl;
    cout << isAnagram("confiers", "fir cones") << endl;
    cout << isAnagram("paulo", "google") << endl;
    cout << isAnagram("laulo", "saulo") << endl;
    cout << isAnagram("william shakespeare", "i am a weakish speller") << endl;
    cout << isAnagram("blabla", "lala") << endl;

    return 0;
}
    
