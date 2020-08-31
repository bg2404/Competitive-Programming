#include<bits/stdc++.h>

using namespace std;

int n, m, k;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int len = 1) {
    color[v] = 1;
    for (int u : adj[v]) {
        if(u == parent[v]) {
            continue;
        }
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool isCyclic() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v))
            break;
    }

    if (cycle_start == -1) {
        return false;
    } else {
        set<int> cycle;
        cycle.insert(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.insert(v);
        map<int, bool> safe;
        while(cycle.size() > k) {
            for(auto u: cycle) {
                int cnt = 0;
                if(safe[u]) {
                    continue;
                }
                for(auto v: adj[u]) {
                    if(cycle.count(v)) {
                        ++cnt;
                        if(parent[u] != v && parent[v] != u && !(v == cycle_start && u == cycle_end) && !(u == cycle_start && v == cycle_end)) {
                            parent[u] = v;
                            cnt = 3;
                            break;
                        }
                    }
                }
                if(cnt == 2) {
                    safe[u] = true;
                } else {
                    cycle.clear();
                    cycle.insert(cycle_start);
                    for (int v = cycle_end; v != cycle_start; v = parent[v])
                        cycle.insert(v);
                }
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m >> k;
    adj = vector<vector<int> > (n, vector<int>());
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cyclic = isCyclic();
    if(!cyclic) {
        vector<int> ans;
        set<int> s;
        for(int i = 0; i < n; ++i) {
            if(adj[i].size() == 1) {
                s.insert(i);
            }
        }
        while(!s.empty()) {
            int v = *s.begin();
            s.erase(s.begin());
            ans.push_back(v + 1);
            if(parent[v] != -1) {
                if(parent[parent[v]] != -1) {
                    s.insert(parent[parent[v]]);
                }
            }
        }
        cout << 1 << '\n';
        for(int i = 0; i <= k/2; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
