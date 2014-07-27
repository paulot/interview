// Given a string print all permutations

#include <string>
#include <iostream>

using namespace std;

void permHelp (string toSelect, string selected) {
    if (toSelect.size() == 0) {
        cout << selected << endl; 
        return;
    }

    int size = toSelect.size();
    for (int i = 0; i < size; i++) {
        // Print solething from toSlect
        // cout << toSelect[0];
        // Add the printed char to selected
        selected += toSelect[0];
        // Delete the printed char from toSelect
        toSelect.erase(0,1);
    }
    // Run again
    permHelp(toSelect, selected);
}

int main() {
    //for (int i = 0; i < 4; i++)
    permHelp("abcd", "");

    return 0;
}
