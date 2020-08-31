// Time Complexity - Preprocessing O(nlogn) Query O(logn)
// Work Space - O(nlogn)
#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > adj;
vector<int> tin, tout;
vector<vector<int> > ancestor;

int timer = 0;
int l;

void dfs(int u = 0, int p = 0) {
    tin[u] = timer++;
    ancestor[u][0] = p;
    for(int i = 1; i <= l; ++i) {
        ancestor[u][i] = ancestor[ancestor[u][i-1]][i-1];
    }
    for(int v: adj[u]) {
        if(v != p) {
            dfs(v, u);
        }
    }
    tout[u] = timer++;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if(is_ancestor(u, v)) {
        return u;
    }
    if(is_ancestor(v, u)) {
        return v;
    }
    for(int i = l; i >= 0; --i) {
        if(!is_ancestor(ancestor[u][i], v)) {
            u = ancestor[u][i];
        }
    }
    return ancestor[u][0];
}

int main() {
    int n;
    cin >> n;
    l = 1 + log2(n);
    adj.assign(n, vector<int>());
    ancestor.assign(n, vector<int>(l));
    tin.resize(n);
    tout.resize(n);

    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    int m;
    cin >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u-1, v-1) + 1 << '\n';
    }
    return 0;
}