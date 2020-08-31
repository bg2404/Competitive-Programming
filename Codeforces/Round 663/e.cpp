#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > adj, levelOrder;
vector<int> depth;
vector<int> parent;
vector<bool> visited;

void dfs(int u = 0, int p = -1, int h = 0) {
    levelOrder[h].push_back(u);
    depth[u] = h;
    parent[u] = p;
    visited[u] = true;
    for(int v: adj[u]) {
        if(!visited[v]) {
            dfs(v, u, h+1);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.assign(n, vector<int>());
    levelOrder.assign(n, vector<int>());
    depth.resize(n);
    parent.assign(n, 0);
    visited.assign(n, false);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs();
    int i = 0;
    while(i < n) {
        if(depth[i] + 1 >= (n+1)/2) {
            break;
        }
        ++i;
    }
    if(i < n) {
        cout << "PATH\n" << depth[i] + 1 << '\n';
        while(i != -1) {
            cout << i + 1 << ' ';
            i = parent[i];
        }
        cout << '\n';
    } else {
        vector<int> a, b;
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j < levelOrder[i].size(); j += 2) {
                a.push_back(levelOrder[i][j-1]);
                b.push_back(levelOrder[i][j]);
            }
        }
        cout << "PAIRING\n" << a.size() << '\n';
        for(int i = 0; i < a.size(); ++i) {
            cout << a[i] + 1 << ' ' << b[i] + 1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        // cout << t << ';';
        solve();
    }
    return 0;
}