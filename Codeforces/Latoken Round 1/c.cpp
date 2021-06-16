#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

void dfs(vector<vector<int> > &adj, vector<bool> &vis, int u) {
    for (auto v : adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            dfs(adj, vis, v);
        }
    }
}

int powModP(long long a, int n, int p = MOD) {
    long long b = 1;
    while (n > 0) {
        if (n & 1) {
            b = (b * a) % p;
        }
        a = (a * a) % p;
        n >>= 1;
    }
    return b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        vector<pair<int, int> > edges(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            edges[a[i] - 1].first = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            edges[b[i] - 1].second = i;
        }
        vector<vector<int> > adj(n);
        for (auto [u, v] : edges) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++ans;
                visited[i] = true;
                dfs(adj, visited, i);
            }
        }
        cout << (powModP(2, ans) + MOD) % MOD << endl;
    }
    return 0;
}