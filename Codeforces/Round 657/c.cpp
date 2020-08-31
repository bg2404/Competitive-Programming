#include<bits/stdc++.h>
#define x first
#define y second
#define flower pair<int64_t,int64_t>
using namespace std;

struct sumCompare {
    
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(n);
    long long mb = 0, ans = 0;
    set<flower,  greater<flower> > s;
    for(int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        mb = max(mb, b[i]);
        s.insert({ a[i], b[i] });
    }
    flower mf;
    bool done = false;
    while(n && !s.empty()) {
        mf = *s.begin();
        s.erase(s.begin());
        if(mf.first >= mb) {
            --n;
            ans += mf.first;
            if(mf.second == mb) {
                done = true;
            }
        } else {
            if(n == 1) {
                ans += mf.first;
                --n;
            }
            break;
        }
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