// Given a paragraph of text, write a program to find the first 
// shortest sub-segment that contains each of the given k words 
// at least once. A segment is said to be shorter than other if 
// it contains less number of words.

#include <iostream>
#include <string>
#include <map>
#include <cctype>
#define isspecial(c) c == '.' or c == ',' or c == ';' or c == '-'

using namespace std;

string paragraph;
map<string, bool> lookup;
int k;

bool shouldSkip(char c) {
    return isspace(c) or isspecial(c);
}

void ToLower(string &s) {
    for (int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
}

void search() {
    // For every word check if it's there
    int start = 0;
    int  len = 0;
    int count = 0;
    int seqBegin = 0;
    // cout << paragraph << endl;
    for (int i = 0; i < paragraph.size(); i++) {
        start = i;
        while (shouldSkip(paragraph[i]) and i < paragraph.size()) {
            start++;
            i++;
        }
        len = 0;
        while (not shouldSkip(paragraph[i]) and i < paragraph.size()) {
            len++;
            i++;
        }
        string word = paragraph.substr(start, len);
        ToLower(word);
        // cout << word << endl;
        if (lookup.find(word) == lookup.end()) {
            // Not found
            count = 0;
            for (map<string, bool>::iterator it = lookup.begin(); it != lookup.end(); ++it) {
                  it->second = false;
            }
        } else if (not lookup[word]) {
            if (count == 0)
                seqBegin = start;
            count++;
            lookup[word] = true;
        }

        if (count == k) {
            paragraph.substr(seqBegin, i - seqBegin);
            for (int i = 0; i < paragraph.substr(seqBegin, i - seqBegin).size(); i++) {
                if (isspecial(paragraph.substr(seqBegin, i - seqBegin)[i]))
                    continue;
                cout << paragraph.substr(seqBegin, i - seqBegin)[i];
            }
            cout << endl;
            return;
        }
    }
    cout << "NO SUBSEGMENT FOUND" << endl;
}

int main() {
    getline(cin, paragraph);

    cin >> k;
    string s; 
    for (int i = 0; i < k; i++) {
        cin >> s;
        ToLower(s);
        lookup[s] = false;
    }

    search();

    return 0;
}
