//https://codeforces.com/problemset/problem/29/C
#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > adj;
vector<int> idxmp, cnt, ans;
unordered_map<int, int> mp;

void dfs(int u, int p = -1) {
    ans.push_back(idxmp[u]);
    for(int v: adj[u]) {
        if(v != p) {
            dfs(v, u);
        }
    }
}

int main() {
    int n, u, v, idx = 0;
    cin >> n;
    adj.assign(n+1, vector<int>());
    idxmp.resize(n+1);
    cnt.assign(n+1, 0);
    ans.reserve(n+1);
    for(int i = 0; i < n; ++i) {
        cin >> u >> v;
        if(mp.find(u) == mp.end()) {
            mp[u] = idx;
            idxmp[idx++] = u;
        }
        if(mp.find(v) == mp.end()) {
            mp[v] = idx;
            idxmp[idx++] = v;
        }
        ++cnt[mp[u]];
        ++cnt[mp[v]];
        adj[mp[u]].push_back(mp[v]);
        adj[mp[v]].push_back(mp[u]);
    }
    int i = 0;
    while(i <= n && cnt[i] != 1) ++i;
    if(i > n) {
        cout << -1 << '\n';
        return 0;
    }
    dfs(i);
    for(int i = 0; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}