#include<bits/stdc++.h>

using namespace std;

vector<int> bin;

void toBinary(int n) {
    bin = vector<int>(30, 0);
    int i = 0;
    while(n) {
        bin[i++] = n&1;
        n = n >> 1;
    }
}

void solve() {
    int n;
    cin >> n;
    if(n <= 30) {
        for(int i = 1; i <= n; ++i) {
            cout << i << ' ' << 1 << '\n';
        }
        return;
    }
    toBinary(n-30);
    cout << '\n';
    int count = 30;
    int dir = 1;
    for(int i = 0; i < 30; ++i) {
        if(bin[i] == 0) {
            if(dir == 1) {
                cout << i + 1 << ' ' << 1 << '\n';
            } else {
                cout << i + 1 << ' ' << i + 1 << '\n';
            }
            --count;
        } else {
            int a = (dir == 1) ? 1 : i+1;
            int b = (dir == 1) ? i+2 : 0;
            for(int j = a; j != b; j += dir) {
                cout << i+1 << ' ' << j << '\n';
            }
            dir = dir * -1;
        }
    }
    for(int i = 0; i < count; ++i) {
        if(dir == 1) {
            cout << 31 + i << ' ' << 1 << '\n';
        } else {
            cout << 31 + i << ' ' << 31+i << '\n';
        }
    }
} 

int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ":\n";
        solve(); 
    }
    return 0;
}