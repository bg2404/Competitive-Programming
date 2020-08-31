#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;
vector<vector<pair<int, long long> > > adj;
vector<long long> dist;
long long ans = 0;

void relaxAll() {
    vector<long long> ndist(dist.size(), LONG_LONG_MIN);
    long long ma = -1;
    for(int i = 0; i < adj.size(); ++i) {
        if(dist[i] >= 0) {
            for(auto [v, w]: adj[i]) {
                ndist[v] = max(ndist[v], dist[i] + w);
                ma = max(ma, ndist[v]);
            }
        }
    }
    ans += ma;
    ans %= mod;
    dist = ndist;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    adj = vector<vector<pair<int, long long> > >(n, vector<pair<int, long long> >());
    dist = vector<long long> (n, LONG_LONG_MIN);
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for(int i = 0; i < q; ++i) {
        relaxAll();
    }
    cout << ans << '\n';
    return 0;
}