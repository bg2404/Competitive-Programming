#include<bits/stdc++.h>

using namespace std;

template<typename T>
void printVector(vector<T> v) {
    for(T x: v) {
        cout << x << ' ';
    }
    cout << '\n';
}

vector<char> find_prefix(string &s, int b, int e) {
    int found = 0, state = 0, even = true, i;
    for(i = e; i > b+state; --i) {
        if(s[b+state] == s[i]) {
            ++state;
        } else if(state > 0) {
            state = 0;
            if(s[b] == s[i]) {
                ++state;
            }
        }
    }
    found = true;
    if((b + state - i) % 2 == 0) {
        even = false;
    } else {
        even = true;
    }
    vector<char> v;
    if(found) {
        int n;
        if(even) {
            n = state*2;
        } else {
            n = state*2+1;
        }
        for(int i = 0; i < n && b+i <= e; ++i) {
            v.push_back(s[b+i]);
        }
    }
    return v;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int l = 0, r = s.size()-1;
        vector<char> ans_pre, pre, suf, chose;
        while(s[l] == s[r] && l < r) {
            ans_pre.push_back(s[l]);
            ++l; --r;
        }
        pre = find_prefix(s, l ,r);
        string t = s;
        reverse(t.begin(), t.end());
        suf = find_prefix(t, l, r);

        if(pre.size() > suf.size()) {
            chose = pre;
        } else {
            chose = suf;
        }
        for(char u: ans_pre) {
            cout << u;
        }
        for(char u: chose) {
            cout << u;
        }
        for(int i = ans_pre.size()-1; i>=0; --i) {
            cout << ans_pre[i];
        }
        cout << '\n';

    }
    return 0;
}