//https://codeforces.com/contest/1325/problem/f

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<int> color;

pair<int, int> z_e, o_e, t_e;
bool z_f = false, o_f = false, t_f = false;

vector<pair<int, int> > edges;

void bfs() {
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        color[v] = 1;
        for(auto u : adj[v]) {
            if(color[u] == 2 && adj[v].size() == 1) {
                if(!z_f) {
                    z_f = true;
                    z_e = {v, u};
                } else if(!o_f) {
                    o_f = true;
                    o_e = {v, u};
                } else if(!t_f) {
                    t_f = true;
                    t_e = {v, u};
                }
            } else if(color[u] == 0) {
                q.push(u);
            }
        }
        color[v] = 2;
    }
}

int main() {
    int n, u, v;
    cin >> n;
    adj.resize(n);
    color.resize(n);
    color.assign(n, 0);
    for(int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        --u; --v;
        edges.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int num = 0;
    for(int i = 0; i < n; ++i) {
        if(!z_f && adj[i].size() == 1) {
            z_e = {i, adj[i][0]};
            z_f = true;
        } else if(!o_f && adj[i].size() == 1) {
            o_e = {i, adj[i][0]};
            o_f = true;
        } else if(!t_f && adj[i].size() == 1) {
            t_e = {i, adj[i][0]};
            t_f = true;
        }
    }

    int nums = n-2;

    // for(int i = 0; i < n; ++i) {
    //     cout << color[i] << ' ';
    // }
    // cout << '\n';

    // cout << o_e.first << ' ' << o_e.second << '\n';

    for(int i = 0; i < n-1; ++i) {
        if( (edges[i].first == z_e.first && edges[i].second == z_e.second) || (edges[i].second == z_e.first && edges[i].first == z_e.second) ) {
            cout << 0 << '\n';
        } else if( (edges[i].first == o_e.first && edges[i].second == o_e.second) || (edges[i].second == o_e.first && edges[i].first == o_e.second) ) {
            cout << 1 << '\n';
        } else if(t_f && ( (edges[i].first == t_e.first && edges[i].second == t_e.second) || (edges[i].second == t_e.first && edges[i].first == t_e.second) ) ) {
            cout << 2 << '\n';
        } else {
            cout << nums-- << '\n';
        }
    }

    return 0;
}