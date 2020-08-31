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

void buildSparseTable(int u = 0) {
    dfs(u);
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
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int> > (2*m-1, vector<int> ());
    first = height = vector<int> (2*m-1, 2*m);
    vector<int> tower(n), cur(m);
    for(int i = 0; i < n; ++i) {
        cin >> tower[i];
        --tower[i];
    }
    for(int i = 0; i < m; ++i) {
        cur[i] = i;
    }
    for(int i = 0; i+1 < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[m+i].push_back(cur[u]);
        adj[m+i].push_back(cur[v]);
        cur[u] = m + i;
    }
    vector<int> psum(m, 0);
    buildSparseTable(2*m-2);
    for(int i = 0; i + 1 < n; ++i) {
        int t = lca(tower[i], tower[i+1]);
        if(t < m) {
            ++psum[0];
        } else {
            ++psum[t-m+1];
        }
    }
    for(int i = 1; i < m; ++i) {
        psum[i] += psum[i-1];
    }
    for(int i = 0; i < m; ++i) {
        cout << n - psum[i] - 1 << '\n';
    }
    return 0;
}