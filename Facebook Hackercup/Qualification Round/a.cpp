#include<bits/stdc++.h>

using namespace std;

void solve(int T) {
    int n;
    cin >> n;
    string in, out;
    cin >> in >> out;
    vector<string> ans(n, string(n, 'Y'));
    for(int i = n-2; i >= 0; --i) {
        if(out[i] == 'N' || in[i+1] == 'N') {
            for(int j = i + 1; j < n; ++j) {
                ans[i][j] = 'N';
            }
        } else {
            for(int j = i + 1; j < n; ++j) {
                ans[i][j] = ans[i+1][j];
            }
        }
    }
    for(int i = 1; i < n; ++i) {
        if(out[i] == 'N' || in[i-1] == 'N') {
            for(int j = 0; j < i; ++j) {
                ans[i][j] = 'N';
            }
        } else {
            for(int j = 0; j < i; ++j) {
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    cout << "Case #" << T << ":\n";
    for(int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }
}

int main() {
    freopen("a.txt", "r", stdin);
    freopen("aout.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}