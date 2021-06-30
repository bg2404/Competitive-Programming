#include <bits/stdc++.h>

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
vector<int> tin, tout, parent;

int dfs(int u, int p = -1, int t = 0) {
    tin[u] = t++;
    parent[u] = p;
    for (int v : adj[u]) {
        if (v != p) {
            t = dfs(v, u, t);
        }
    }
    tout[u] = t++;
    return t;
}

bool isAncestor(int u, int v) {
    return tin[u] < tin[v] && tout[v] < tout[u];
}

int main() {
    int n, u, v;
    cin >> n;
    adj.resize(n);
    tin.resize(n);
    tout.resize(n);
    parent.resize(n);
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    cout << tin << endl
         << tout << endl
         << parent << endl;
    return 0;
}