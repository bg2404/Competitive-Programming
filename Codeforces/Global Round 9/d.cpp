#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n+1);
    set<int> s;
    for(int i = 0; i <= n; ++i) {
        s.insert(i);
    }
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(c[a[i]] == 0) {
            s.erase(a[i]);
        }
        ++c[a[i]];
    }
    // for(auto x: s) {
    //     cout << x << ' ';
    // }
    // cout << '\n';
    vector<int> ans;
    for(int i = 0; i < n; ++i) {
        if(a[i] == i) {
            continue;
        }
        while(*s.begin() != i) {
            int new_v = *s.begin();
            c[new_v] = 1;
            s.erase(s.begin());

            if(new_v == n) {
                --c[a[i]];
                if(c[a[i]] == 0) {
                    s.insert(a[i]);
                }
                a[i] = new_v;
                ans.push_back(i);
            } else {
                --c[a[new_v]];
                if(c[a[new_v]] == 0) {
                    s.insert(a[new_v]);
                }
                a[new_v] = new_v;
                ans.push_back(new_v);
            }
        }
        int new_v = *s.begin();
        c[new_v] = 1;
        s.erase(s.begin());

        --c[a[new_v]];
        if(c[a[new_v]] == 0) {
            s.insert(a[new_v]);
        }
        a[new_v] = new_v;
        ans.push_back(new_v);
    }

    cout << ans.size() << '\n';
    for(auto x: ans) {
        cout << x  + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}