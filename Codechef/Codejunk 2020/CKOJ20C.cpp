#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > adj;
bool is_prime[200001];
vector<int> a;
vector<pair<int, int> > dp;
void sieve(int n = 200000) {
    memset(is_prime, true, n+1);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; ++i) {
        if(is_prime[i]) {
            for(int j = i + i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void initDP(int u = 0, int p = -1) {
    int first = 0, second = 0;
    for(int v: adj[u]) {
        if(v == p) {
            continue;
        }
        initDP(v, u);
        first += max(0, dp[v].first);
        second += max(0, dp[v].second);
    }
    if(is_prime[a[u]]) {
        dp[u] = {1, -1};
    } else {
        dp[u] = {-1, 1};
    }
    dp[u].first += first;
    dp[u].second += second;
}

void dfs(int u = 0, int p = -1) {
    if(p == -1) {
        initDP();
    } else {
        int pf = dp[p].first, ps = dp[p].second;
        pf -= max(dp[u].first, 0); ps -= max(dp[u].second, 0);
        dp[u].first += max(0, pf);
        dp[u].second += max(0, ps);
    }
    for(int v: adj[u]) {
        if(v == p) {
            continue;
        }
        dfs(v, u);
    }
}

int main() {
    sieve();
    int n;
    cin >> n;
    a = vector<int> (n);
    adj = vector<vector<int> > (n, vector<int>());
    dp = vector<pair<int, int> > (n, {INT_MIN, INT_MIN});
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    for(int i = 0; i < n; ++i) {
        cout << max(dp[i].first, dp[i].second) << ' ';
    }
    cout << '\n';
    return 0;
}