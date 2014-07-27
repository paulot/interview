
#include <iostream>
#include <string>

using namespace std;

// There are 26, divided into 5
void getControl(char c, int i, int j) {
    int row = (c-'a')/5;
    int col = (c-'a')%5;
    row -= i;
    col -= j;
    char ro = (row < 0) ? 'u' : 'd';
    char co = (col < 0) ? 'l' : 'r';
    row = (row < 0) ? -row : row;
    col = (col < 0) ? -col : col;
    for (int i = 0; i < col; i++) cout << co;
    for (int i = 0; i < row; i++) cout << ro;
    cout << '!';
}

void getMovie(string &movie) {
    char c = 'a';
    for (int i = 0; i < movie.size(); i++) {
        getControl(movie[i], (c-'a')/5, (c-'a')%5);
        c = movie[i];
    }
    cout << endl;
}

int main() {
    string m = "mz";
    getMovie(m);
    return 0;
}
