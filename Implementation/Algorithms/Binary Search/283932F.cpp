#include<bits/stdc++.h>

using namespace std;

vector<int> cntt(26, 0), cntp(26, 0);

bool isFeasible(string &t,  vector<int> &a, int n, int m) {
    vector<int> cnt(cntt.begin(), cntt.end());
    for(int i = 0; i < m; ++i) {
        --cnt[t[a[i]-1]-'a'];
    }
    for(int i = 0; i < 26; ++i) {
        if(cnt[i] < cntp[i]) {
            return false;
        }
    }
    return true;
}

int solve(string &t, vector<int> &a, int n) {
    int l = 0, r = n, ans = l, m;
    while(l <= r) {
        m = l + r >> 1;
        if(isFeasible(t, a, n, m)) {
            ans = max(ans, m);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans;
}

int main() {
    string t, p;
    cin >> t >> p;
    vector<int> a(t.size());
    for(int &i: a) {
        cin >> i;
    }
    for(char c: t) {
        ++cntt[c - 'a'];
    }
    for(char c: p) {
        ++cntp[c - 'a'];
    }
    cout << solve(t, a, t.size());
    return 0;
}