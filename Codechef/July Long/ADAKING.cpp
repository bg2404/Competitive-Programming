#include<bits/stdc++.h>

using namespace std;

void solve() {
    int K;
    cin >> K;
    char board[8][8];
    memset(board, 'X', sizeof(board));
    for(int i = 0; i < 8 && K; ++i) {
        for(int j = 0; j < 8 && K; ++j, --K) {
            board[i][j] = '.';
        }
    }
    board[0][0] = 'O';
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}