#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int> > edges;
vector<vector<int> > adj;
vector<int> torder, color;
vector<bool> visited;
vector<int> cl;

void topological_sort_util(int v) {
    visited[v] = true;
    for(auto u: adj[v]) {
        if(!visited[u]) {
            topological_sort_util(u);
        }
    }
    torder.push_back(v);
}

void topological_sort(int n) {
    visited = vector<bool>(n, false);
    torder.clear();
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            topological_sort_util(i);
        }
    }
    reverse(torder.begin(), torder.end());
}

bool is_cyclic_util(int v) {
    color[v] = 1;
    for(auto u: adj[v]) {
        if(color[u] == 1 || (!color[u] && is_cyclic_util(u))) {
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool is_cyclic(int n) {
    color = vector<int> (n, 0);
    for(int i = 0; i < n; ++i) {
        if(!color[i]) {
            if(is_cyclic_util(i)) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int> > (n, vector<int>());
    edges.clear();
    cl = vector<int> (n);
    vector<pair<int, int> > ans;
    for(int i = 0; i < m; ++i) {
        int t, v, u;
        cin >> t >> v >> u;
        --v; --u;
        if(t == 1) {
            adj[v].push_back(u);
            ans.push_back({v, u});
        } else {
            edges.push_back({v, u});
        }
    }
    if(is_cyclic(n)) {
        cout << "NO\n";
        return;
    }
    topological_sort(n);
    // for(auto v: torder) {
    //     cout << v << ' ';
    // }
    for(int i = 0; i < n; ++i) {
        cl[torder[i]] = i;
    }
    for(auto e: edges) {
        int v = e.first, u = e.second;
        if(cl[v] < cl[u]) {
            ans.push_back({v, u});
        } else {
            ans.push_back({u, v});
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}