// Time Complexity - Preprocessing O(nlogn) Query O(1)
// Work Space - O(nlogn)
#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > adj, sparse;
vector<int> euler, first, height;

void dfs(int u = 0, int p = -1, int h = 0) {
    euler.push_back(u);
    first[u] = euler.size() - 1;
    height[u] = h;
    for(int v: adj[u]) {
        if(v != p) {
            dfs(v, u, h + 1);
            euler.push_back(u);
        }
    }
}

void buildSparseTable() {
    dfs();
    int n = euler.size();
    int m = 1 + log2(n);
    sparse = vector<vector<int> >(n, vector<int> (m, -1));
    for(int i = 0; i < n; ++i) {
        sparse[i][0] = euler[i];
    }
    for(int j = 1; j < m; ++j) {
        for(int i = 0; i + (1 << j) <= n; ++i) {
            sparse[i][j] = sparse[i][j-1];
            if(height[sparse[i][j-1]] > height[sparse[i + (1 << (j-1))][j-1]]) {
                sparse[i][j] = sparse[i + (1 << (j-1))][j-1];
            }
        }
    }
}

int query(int l, int r) {
    int m = log2(r - l + 1);
    if(height[sparse[l][m]] > height[sparse[r-(1<<m)+1][m]]) {
        return sparse[r-(1<<m)+1][m];
    }
    return sparse[l][m];
}

int lca(int u, int v) {
    int l = first[u], r = first[v];
    if(l > r) {
        swap(l, r);
    }
    return query(l, r);
}

int main() {
    int n;
    cin >> n;
    adj = vector<vector<int> > (n, vector<int> ());
    first = height = vector<int> (n, n + 1);
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    buildSparseTable();
    int m;
    cin >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u-1, v-1) + 1 << '\n';
    }
    return 0;
}