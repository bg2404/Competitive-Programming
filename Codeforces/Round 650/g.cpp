#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > a(n+1, {0, 0});
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ++a[x].first;
        a[x].second += y;
    }
    sort(a.begin(), a.end());
    int ans = 0, f = 0, p = n+1;
    int i = n;
    multiset<int, greater<int> > unused;
    while(i > 0 && p > 1) {
        if(a[i].first == 0) {
            --i;
            continue;
        }
        if(a[i].first < p) {
            if(unused.empty()) {
                p = a[i].first;
                ans += p;
                f += a[i].second;
                --i;
            } else {
                --p;
                ans += p;
                if(a[i].first == p) {
                    int unused_max = *unused.begin();
                    if(a[i].second >= unused_max) {
                        f += a[i].second;
                        --i;
                    } else {
                        f += min(p, unused_max);
                        unused.erase(unused.begin());
                    }
                } else {
                    int unused_max = *unused.begin();
                    f += min(unused_max, p) ;
                    unused.erase(unused.begin());
                }
            }
        } else {
            while(i > 0 && p == a[i].first) {
                unused.insert(a[i].second);
                --i;
            }
        }
    }
    while(p > 1 && !unused.empty()) {
        --p;
        ans += p;
        int unused_max = *unused.begin();
        f += min(p, unused_max);
        unused.erase(unused.begin());
    }
    cout << ans << ' ' << f << '\n';
}

int main() {
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}