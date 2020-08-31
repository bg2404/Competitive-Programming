#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> v;
    int c = s[0] == '1';
    for(int i = 1; i < n; ++i) {
        if(s[i] == '1') {
            ++c;
        } else {
            v.push_back(c);
            c = 0;
        }
    }
    v.push_back(c);
    sort(v.begin(), v.end());
    int a[2] = {0, 0};
    for(int i = 0; v.size(); ++i) {
        a[i&1] += v.back();
        v.pop_back();
    }
    cout << a[0] << '\n';
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