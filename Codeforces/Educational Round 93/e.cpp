#include<bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    set<long long> l;
    set<long long, greater<long long> > f;
    long long ls = 0, fs = 0, ans;
    for(int i = 0; i < n; ++i) {
        long long tp, d;
        cin >> tp >> d;
        if(tp == 0) {
            fs += d;
            if(d > 0) {
                f.insert(d);
            } else {
                f.erase(-d);
            }
        } else {
            ls += d;
            if(d > 0) {
                l.insert(d);
            } else {
                l.erase(-d);
            }
        }
        ans = ls + ls + fs;
        if(!l.empty()) {
            ans -= *l.begin();
        }
        if(!f.empty() && !l.empty()) {
            ans += *f.begin();
        }
        cout << ans << '\n';
    }
    return 0;
}