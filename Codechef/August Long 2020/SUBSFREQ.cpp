#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<vector<int> > nCr;

void init(int n) {
    nCr.assign(n+1, vector<int>(n+1, -1));
    nCr[0][0] = nCr[1][0] = nCr[1][1] = 1;
    for(int i = 2; i <= n; ++i) {
        nCr[i][0] = nCr[i][i] = 1;
        for(int j = 1; j < i; ++j) {
            nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            nCr[i][j] = (nCr[i][j] + nCr[i][j-1]) % MOD;
        }
    }
}

void solve1(int n) {
    vector<int> cnt(n+2, 0);
    int a;
    for(int i = 0; i < n; ++i) {
        cin >> a;
        ++cnt[a];
    }
    int ans = 0;
    vector<int> out;
    for(int i = 1; i <= n; ++i) {
        long long cur;
        ans = 0;
        for(int j = 1; j <= cnt[i]; ++j) {
            cur = nCr[cnt[i]][j] - nCr[cnt[i]][j-1];
            // cout << cur << ' ';
            for(int k = 1; k < i; ++k) {
                cur = (cur * nCr[cnt[k]][min(cnt[k], j-1)]) % MOD;
            }
            // cout << cur << ' ';
            for(int k = i + 1; k <= n; ++k) {
                cur = (cur * nCr[cnt[k]][min(cnt[k], j)]) % MOD;
            }
            // cout << cur << '\n';
            ans = (ans + cur) % MOD;
        }
        out.push_back(ans);
    }
    for(int ans: out) {
        cout << ans << ' ';
    }
    cout << '\n';
}

void solve2(int n) {
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
    }
    int cur = 1;
    for(int i = n-1; i >= 0; --i) {
        a[i] = cur;
        cur <<= 1;
        cur %= MOD;
    }
    for(int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    init(5000);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n > 5000) {
            solve2(n);
        } else {
            solve1(n);
        }
    }
}