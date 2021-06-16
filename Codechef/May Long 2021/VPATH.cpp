#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    os << "[ ";
    for (T e : v) {
        os << e << ' ';
    }
    os << ']';
    return os;
}

vector<vector<int> > adj;
vector<long long> dp;

long long dfs(int u = 0, int p = -1) {
    long long ans = 1;
    for (int v : adj[u]) {
        if (v != p) {
            ans += dfs(v, u);
            ans %= MOD;
        }
    }
    long long sum = 0;
    for (int v : adj[u]) {
        if (v != p) {
            sum += dp[v];
            sum %= MOD;
        }
    }
    dp[u] = sum + sum + 1;
    dp[u] %= MOD;
    ans += sum;
    ans %= MOD;
    for (int v : adj[u]) {
        if (v != p) {
            ans += 2 * (sum -= dp[v]) * dp[v];
            ans %= MOD;
            sum %= MOD;
        }
    }
    // cout << u << ": " << ans << endl;
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        adj.assign(N, vector<int>());
        dp.assign(N, 0);
        for (int i = 1; i < N; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ans = ((dfs() % MOD) + MOD) % MOD;
        // cout << dp << endl;
        cout << ans << endl;
    }
    return 0;
}