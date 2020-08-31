#include<bits/stdc++.h>

using namespace std;

struct EDGE {
    int to;
    int w;
};

vector<vector<EDGE> > adj;
vector<pair<int, EDGE> > edges;
vector<int> leaves;

int dfs(int root = 0, int p = -1) {
    int cnt = 0;
    for(EDGE e: adj[root]) {
        if(e.to != p) {
            cnt += dfs(e.to, root);
        }
    }
    return leaves[root] = (cnt == 0) ? 1 : cnt;
}

struct comp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const {
        return ((long long)a.first)*(a.second - a.second/2) > ((long long)b.first)*(b.second - b.second/2);
    }
};

void solve() {
    int n, u, v, w;
    long long S;
    cin >> n >> S;
    adj.assign(n, vector<EDGE>());
    edges.clear();
    edges.reserve(n-1);
    leaves.assign(n, 0);
    for(int i = 1; i < n; ++i) {
        cin >> u >> v >> w;
        --u; --v;
        edges.push_back({u, {v, w}});
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs();
    multiset<pair<int, int>, comp> s;
    long long totalWeight = 0;
    for (int i = 0; i < n-1; i++) {
        int u = edges[i].first, v = edges[i].second.to;
        long long w = edges[i].second.w;
        int cnt = min(leaves[u], leaves[v]);
        totalWeight += cnt*w;
        s.insert({cnt, w});
    }
    int ans = 0;
    while(totalWeight > S) {
        pair<int, int> p = *s.begin();
        s.erase(s.begin());
        long long diff = ((long long)p.first)*(p.second - p.second/2);
        totalWeight -= diff;
        if(p.second > 1) {
            s.insert({p.first, p.second/2});
        }
        ++ans;
    }
    cout << ans << '\n';    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}