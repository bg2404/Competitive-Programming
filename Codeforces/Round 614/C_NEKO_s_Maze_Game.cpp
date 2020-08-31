#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

bool maze[2][100002];
int closed = 0;

void update(int r, int c) {
    int o = r ^ 1;
    int count = 0;
    if(maze[o][c-1]) {
        count++;
    }
    if(maze[o][c]) {
        count++;
    }
    if(maze[o][c+1]) {
        count++;
    }
    if(maze[r][c]) {
        maze[r][c] = false;
        closed -= count;
    } else {
        maze[r][c] = true;
        closed += count;
    }
}

int32_t main() {
    int T = 1;
    // cin >> T;
    while(T--) {
        int n, q;
        cin >> n >> q;
        int r, c;
        for(int i = 0; i < q; ++i) {
            cin >> r >> c;
            update(r-1,c);
            if(closed == 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
    return 0;
}