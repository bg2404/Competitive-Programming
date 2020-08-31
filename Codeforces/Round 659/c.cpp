#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

vector<int> parent, sz;

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    parent = sz = vector<int>(20);
    for(int i = 0; i < 20; ++i) {
        make_set(i);
    }
    if(a == b) {
        cout << 0 << '\n';
        return;
    }
    vector<vector<int> > cnt(20, vector<int> (20, 0));
    for(int i = 0; i < n; ++i) {
        if(a[i] > b[i]) {
            cout << -1 << '\n';
            return;
        } else if(a[i] < b[i]) {
            ++cnt[a[i]-'a'][b[i]-'a'];
        }
    }
    int ans = 0;
    vector<bool> done(20, false);
    for(int i = 1; i < 20; ++i) {
        int moves = 0;
        set<int> s;
        for(int j = 0; j < i; ++j) {
            if(cnt[j][i]) {
                ++moves;
                s.insert(find_set(j));
            }
        }
        if(moves) {
            ans += s.size();
        }
        for(int u: s) {
            union_sets(u, i);
        }
    }
    cout << ans << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}