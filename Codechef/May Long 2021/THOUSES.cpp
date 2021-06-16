#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long dfs(vector<vector<int> > &adj, int u = 0, int p = -1) {
    vector<long long> values;
    for (int v : adj[u]) {
        if (v != p) {
            values.push_back(dfs(adj, v, u));
        }
    }
    int m = 1;
    long long sum = 1;
    sort(values.rbegin(), values.rend());
    for (long long v : values) {
        sum += v * m++;
        sum %= MOD;
    }
    return sum;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        long long X;
        cin >> N >> X;
        vector<vector<int> > adj(N);
        for (int i = 1; i < N; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ans = (dfs(adj) % MOD) * X;
        cout << (ans % MOD + MOD) % MOD << endl;
    }
    return 0;
}