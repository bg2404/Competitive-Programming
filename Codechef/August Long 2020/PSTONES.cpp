#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<vector<int> > adj;

void solve() {
    int n, k;
    cin >> n >> k;
    adj.assign(n+1, vector<int>());
    vector<int> color(n);
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v >> color[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int l = 1; l <= n; ++l) {
        string s((1<<k), '0');
        for(int b = 1; b <= n; ++b) {
            int x = b-1, y = b + l - 1;
            if(y <= n) {
                int num = 0;
                if(x > 0 && x < n) {
                    num = num | (1 << (color[x]-1));
                }
                if(y > 0 && y < n) {
                    num = num | (1 << (color[y]-1));
                }
                s[num] = '1';
            }
        }
        cout << s << '\n';
    }

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
}