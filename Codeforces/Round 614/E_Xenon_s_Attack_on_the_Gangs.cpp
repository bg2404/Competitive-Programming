#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int n, root;
vector<vector<int> > tree, sub, par, dp;

void dfs(int u) {
    sub[root][u] = 1;

    for(int v: tree[u]) {
        if(v == par[root][u]) {
            continue;
        }
        par[root][v] = u;
        dfs(v);
        sub[root][u] += sub[root][v];
    }
}

int getDP(int u, int v) {
    if(u == v) {
        return 0;
    } if(dp[u][v] != -1) {
        return dp[u][v];
    }

    long long res = sub[v][u]*sub[u][v] + max(getDP(par[v][u],v),getDP(u,par[u][v]));
    
    return dp[u][v] = res;
}

void input() {
    scanf("%lld", &n);

    tree.assign(n+5, vector<int>());

    for(int i = 1; i < n; ++i) {
        int u, v;
        scanf("%lld %lld", &u, &v);
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}

void solve() {
	par.assign(n, vector<int>(n, -1));
	sub.assign(n, vector<int>(n, -1));
    for(int i = 0; i < n; ++i) {
        root = i;
        dfs(i);
        cout << '\n';
    }
    
    int ans = -1;
    dp.assign(n, vector<int>(n, -1LL));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            ans = max(ans, getDP(i, j));
        }
    }

    printf("%lld\n", ans);
}

int32_t main() {
    input();
    solve();
    return 0;
}