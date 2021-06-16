#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > adj;
vector<int> ans, color;
vector<bool> visited;

void topological_sort_util(int v) {
    visited[v] = true;
    for(auto u: adj[v]) {
        if(!visited[u]) {
            topological_sort_util(u);
        }
    }
    ans.push_back(v);
}

void topological_sort(int n) {
    visited = vector<bool>(n, false);
    ans.clear();
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            topological_sort_util(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

bool is_cyclic_util(int v) {
    color[v] = 1;
    for(auto u: adj[v]) {
        if(color[v] == 1 || (!color[v] && is_cyclic_util(v))) {
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

int main() {
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int> >(n, vector<int>());
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
    }
    if(is_cyclic(n)) {
        cout << "Graph is not DAG\n";
        return 0;
    }
    topological_sort(n);
    for(int v: ans) {
        cout << v << ' ';
    }
    cout << '\n';
    return 0;
} 