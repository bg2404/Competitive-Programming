#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<vector<int> > adj;
vector<int> p, a, b, d, visited;

void dfs(int u, int cur, int day) {
    visited[u] = 1;
    if(b[u] > 0) {
        b[u] = b[u] - min(a[cur], b[u]);
        if(b[u] <= 0) {
            d[u] = day;
        }
    }
    for(int v: adj[u]) {
        if(visited[v] == 0) {
            dfs(v, cur, day);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    adj.assign(n+1, vector<int>());
    p.resize(n+1);
    a.resize(n+1);
    b.resize(n+1);
    d.assign(n+1, -1);
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for(int i = 1; i <= n; ++i) {
        visited.assign(n+1, 0);
        for(int j = 1; j < i; ++j) {
            visited[p[j]] = 1;
        }
        dfs(p[i], p[i], i);
    }
    for(int i = 1; i <= n; ++i) {
        cout << d[i] << ' ';
    }
    cout << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}