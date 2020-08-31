#include<bits/stdc++.h>

using namespace std;

struct EDGE {
    int to;
    int w;
};

vector<vector<EDGE> > adj;
vector<pair<int, EDGE> > edges[2];
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
    int n, u, v, w, c;
    long long S;
    cin >> n >> S;
    adj.assign(n, vector<EDGE>());
    edges[0].clear(); edges[1].clear();
    leaves.assign(n, 0);
    for(int i = 1; i < n; ++i) {
        cin >> u >> v >> w >> c;
        --u; --v;
        edges[c-1].push_back({u, {v, w}});
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs();
    multiset<pair<int, int>, comp> s[2];
    long long totalWeight = 0;
    for(int i = 0; i < 2; ++i) {
        for (int j = 0; j < edges[i].size(); j++) {
            int u = edges[i][j].first, v = edges[i][j].second.to;
            long long w = edges[i][j].second.w;
            int cnt = min(leaves[u], leaves[v]);
            totalWeight += cnt*w;
            s[i].insert({cnt, w});
        }
    }
    vector<long long> diff[2];
    diff[0].push_back(0);
    diff[1].push_back(0);
    for(int i = 0; i < 2; ++i) {
        while(!s[i].empty()) {
            pair<int, int> p = *s[i].begin();
            s[i].erase(s[i].begin());
            diff[i].push_back(diff[i].back() + ((long long)p.first)*(p.second - p.second/2));
            if(p.second > 1) {
                s[i].insert({p.first, p.second/2});
            }
        }
    }
    long long req = totalWeight - S;
    int ans = INT_MAX;
    for(int i = 0; i < diff[0].size(); ++i) {
        int temp = i;
        if(diff[0][i] < req) {
            int j = lower_bound(diff[1].begin(), diff[1].end(), req - diff[0][i]) - diff[1].begin();
            if(j < diff[1].size()) {
                temp += j*2;
            } else {
                continue;
            }
        }
        ans = min(ans, temp);
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