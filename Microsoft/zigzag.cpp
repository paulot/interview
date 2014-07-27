// Write a program to reverse a sentence in a zigzag order. 
// i/p: I am a software programmer 
// o/p: programmer erawtfos a ma I
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

void flip(string &str, int start, int size) {
    int t;
    for (int i = 0; i < size/2; i++) {
        t = str[start + i]; 
        str[start + i] = str[start + size - i - 1];
        str[start + size - i - 1] = t;
    }
}


void invert(string &str) {
    flip(str, 0, str.size());

    int j;
    for (int i = 0; i < str.size();) {
        // Skip leading space
        while (isspace(str[i]) and i < str.size()) i++;

        // Find leading space
        j = i;
        while (!isspace(str[i]) and i < str.size()) i++;
        
        // Flip from j to i
        flip(str, j, i-j);
    }
}

void zigzag(string &str, int skip) {
    flip(str, 0, str.size());

    int j, c = 0;
    for (int i = 0; i < str.size();) {
        // Skip leading space
        if (isspace(str[i])) {
            c++;
            while (isspace(str[i]) and i < str.size()) i++;
        }

        // Find leading space
        j = i;
        while (!isspace(str[i]) and i < str.size()) i++;
        
        // Flip from j to i
        if (!(c % skip))
            flip(str, j, i-j);
    }
}

int main() {
    // string s = "I am a software programmer";
    string s = "abc def ghij";
    zigzag(s, 2);
    cout << s << endl;

    return 0;
}
