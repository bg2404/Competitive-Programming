#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<vector<int> > adj(n, vector<int>());
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    --x;
    if(adj[x].size() < 2) {
        cout << "Ayush\n";
        return;
    }
    if(n & 1) {
        cout << "Ashish\n";
    } else {
        cout << "Ayush\n";
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