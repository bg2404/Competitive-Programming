//https://codeforces.com/contest/1324/problem/F
#include<bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> dp;
vector<int> ans;
vector<vector<int> > g;

void dfs(int v, int p = -1) {
    dp[v] = a[v];
    for(auto to: g[v]) {
        if(to == p) continue;
        dfs(to, v);
        dp[v] += max(0, dp[to]);
    }
}

void dfs2(int v, int p = -1) {
    ans[v] = dp[v];
    for(auto to: g[v]) {
        if(to == p) continue;
        dp[v] -= max(0, dp[to]);
        dp[to] += max(0, dp[v]);
        dfs2(to, v);
        dp[to] -= max(0,dp[v]);
        dp[v] += max(0, dp[to]);
    }
}

int main() {
    int n, u, v;
    cin >> n;
    a.resize(n);
    dp.resize(n);
    ans.resize(n);
    g.resize(n);

    for(int i = 0; i < n; ++i) {
        cin >> a[i];

        if(!a[i]) a[i] = -1;
    }
    for(int i = 1; i < n; ++i) {
        cin >> u >> v; --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);
    dfs2(0);

    for(auto cur: ans) {
        cout << cur << ' ';
    }
    cout << '\n';
    
    return 0;
}