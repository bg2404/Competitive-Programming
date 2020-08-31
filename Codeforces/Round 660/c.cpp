#include<bits/stdc++.h>
#define int long long
using namespace std;

struct city {
    int p;
    int hi;
    int h;
    int s;
};

vector<vector<int> > adj;
vector<city> cities;
vector<int> p, h;

bool dfs(int u, int par = -1) {
    bool ans = true;
    for(int v: adj[u]) {
        if(v != par) {
            if(!dfs(v, u)) {
                ans = false;
            }
            cities[u].p += cities[v].p;
        }
    }
    // cout << '@';
    // cout << u << ' ';
    // cout << cities[u].p << ' ';
    // cout << cities[u].hi << ' ';
    cities[u].h = (cities[u].p + cities[u].hi) / 2;
    cities[u].s = (cities[u].p - cities[u].hi) / 2;
    if((cities[u].p & 1) != (cities[u].hi & 1) || cities[u].p < cities[u].hi) {
        ans = false;
    }
    if(!ans) {
        return false;
    }
    // cout << cities[u].h << ' ';
    // cout << cities[u].s << ' ';
    int h = 0, s = 0;
    for(int v: adj[u]) {
        if(v != par) {
            h += cities[v].h;
            s += cities[v].s;
        }
    }
    // cout << h << ' ';
    // cout << s << ' ';
    // cout << '\n';
    if(h > cities[u].h) {
        // cout << "#";
        return false;
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    p = h = vector<int> (n);
    cities = vector<city> (n);
    for(auto &i: p) {
        cin >> i;
    }
    for(auto &i: h) {
        cin >> i;
    }
    for(int i = 0; i < n; ++i) {
        cities[i].p = p[i];
        cities[i].hi = h[i];
    }
    adj.assign(n, vector<int>());
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(dfs(0, -1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int32_t main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}