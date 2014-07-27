#include <iostream>
#include <queue>
#include <limits.h>
#include <cmath>
#define GETS(x,y,d) ((((d << 8) + x) << 8) + y)
#define GETX(s) ((s >> 8) & 256)
#define GETY(s) ((s & 256))
#define GETD(s) ((s >> 16))
#define size 8

using namespace std;


bool oneMove(int ix, int iy, int dx, int dy) {
    return abs(dy-iy) == abs(dx-ix);
}

int bfs(int ix, int iy, int dx, int dy) {
    bool v[size][size] = { false };
    queue<int> q;
    q.push(GETS(ix,iy,0));

    int d = 0;
    while (not q.empty()) {
        int state = q.front();
        q.pop();
        if (v[GETX(state)][GETY(state)]) continue;
        if (GETX(state) == 3 and GETY(state) == 3) cout << "d " << d << endl;
        v[GETX(state)][GETY(state)] = true;
        if (oneMove(GETX(state), GETY(state), dx, dy)) {
            return GETD(state) + 1;
        }
        d++;
        for (int x = GETX(state), y = GETY(state); x < size and y < size; x++, y++)
            q.push(GETS(x,y, GETD(state) + 1));
        for (int x = GETX(state), y = GETY(state); x >= 0 and y >= 0; x--, y--)
            q.push(GETS(x,y, GETD(state) + 1));
        for (int x = GETX(state), y = GETY(state); x >= 0 and y < size; x--, y++)
            q.push(GETS(x,y, GETD(state) + 1));
        for (int x = GETX(state), y = GETY(state); x < size and y >= 0; x++, y--)
            q.push(GETS(x,y, GETD(state) + 1));
    }
    return -1;
}

int main() {
    int s = GETS(2,3,4);
    cout << GETX(s) << " " << GETY(s) << " " << GETD(s) << endl;
    // cout << bfs(0,0,1,5) << endl;

    return 0;
}
