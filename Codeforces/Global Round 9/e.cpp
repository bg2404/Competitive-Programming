#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    vector<pair<int, int> > b(n), ans;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b.begin(), b.end());
    for(int i = 0; i < n; ++i) {
        a[b[i].second] = i;
    }
    for(int i = 0; i < n; ++i) {
        p[a[i]] = i;
    }
    for(int i = n-1; i >= 0; --i) {
        for(int j = a[i] + 1; j <= i; ++j) {
            swap(a[p[j]], a[i]);
            ans.push_back( { p[j], p[j-1] } );
            swap(p[j], p[j - 1]);
        }
    }
    cout << ans.size() << '\n';
    for(auto x: ans) {
        cout << x.first + 1 << ' ' << x.second + 1 << '\n';
    }

    return 0;
}