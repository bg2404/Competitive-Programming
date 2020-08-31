#include<bits/stdc++.h>

using namespace std;

bool has_Zero(long long n) {
    string s = to_string(n);
    for(auto c: s) {
        if(c == '0')
            return true;
    }
    return false;
}

pair<int, int> min_max(long long n) {
    string s = to_string(n);
    char mi = '9', ma = '0';
    for(auto c: s) {
        mi = min(mi, c);
        ma = max(ma, c);
    }
    return {mi-'0', ma-'0'};
}

int solve() {
    long long a, k;
    cin >> a >> k;
    while(!has_Zero(a) && --k) {
        pair<int, int> p = min_max(a);
        a += p.first*p.second;
    }
    cout << a << '\n';
    return 0;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}