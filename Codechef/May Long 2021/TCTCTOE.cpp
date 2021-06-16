#include <bits/stdc++.h>

using namespace std;

bool checkWin(char grid[3][3], char c) {
    for (int i = 0; i < 3; ++i) {
        if (grid[0][i] == c && grid[1][i] == c && grid[2][i] == c) {
            return true;
        }
        if (grid[i][0] == c && grid[i][1] == c && grid[i][2] == c) {
            return true;
        }
    }
    if (grid[0][0] == c && grid[1][1] == c && grid[2][2] == c) {
        return true;
    }
    if (grid[2][0] == c && grid[1][1] == c && grid[0][2] == c) {
        return true;
    }
    return false;
}

int isReachable(char grid[3][3]) {
    int count_x = 0, count_o = 0;
    bool empty = false;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == 'X') {
                ++count_x;
            } else if (grid[i][j] == 'O') {
                ++count_o;
            } else {
                empty = true;
            }
        }
    }
    bool win_x = checkWin(grid, 'X'), win_o = checkWin(grid, 'O');
    if (!(count_x == count_o || count_x == count_o + 1) || (win_x && win_o) || (win_x && count_x == count_o) || (win_o && count_x == count_o + 1)) {
        return 3;
    }
    if (win_x || win_o || count_x + count_o == 9) {
        return 1;
    }
    return 2;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        char grid[3][3];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> grid[i][j];
            }
        }
        cout << isReachable(grid) << endl;
    }
    return 0;
}