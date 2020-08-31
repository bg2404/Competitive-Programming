#include<bits/stdc++.h>

using namespace std;

vector<int> suffix_array(string &s, vector<int> &p, vector<int> &c) {
    s.push_back('$');
    int n = s.size();
    {
        vector<pair<char, int> > a(n);
        for(int i = 0; i < n; ++i) {
            a[i] = {s[i], i};
        }

        sort(a.begin(), a.end());

        for(int i = 0; i < n; ++i) {
            p[i] = a[i].second;
        }

        c[p[0]] = 0;
        for(int i = 1; i < n; ++i) {
            c[p[i]] = c[p[i-1]] + (a[i].first != a[i-1].first);
        }
    }

    int k = 0;
    while( (1 << k) < n ) {
        vector<pair<pair<int, int>, int> > a(n);
        for(int i = 0; i < n; ++i) {
            a[i] = { {c[i], c[(i + (1 << k)) % n]}, i};
        }

        sort(a.begin(), a.end());

        for(int i = 0; i < n; ++i) {
            p[i] = a[i].second;
        }

        c[p[0]] = 0;
        for(int i = 1; i < n; ++i) {
            c[p[i]] = c[p[i-1]] + (a[i].first != a[i-1].first);
        }
        ++k;
    }
    return p;
}

int main() {
    string s, t;
    cin >> s >> t;
    int m = s.size();
    s = s + '-' + t;
    int n = s.size() + 1, k;
    vector<int> c(n), p(n);
    suffix_array(s, p, c);

    vector<int> lcp(n);
    k = 0;
    for(int i = 0; i + 1 < n; ++i) {
        int pi = c[i];
        int j = p[pi - 1];
        while(s[i+k] == s[j+k] && i + k < n && j + k < n) ++k;
        lcp[pi] = k;
        k = max(0, k - 1);
    }
    string ans = "";
    int maxlen = 0, maxidx = -1;
    for(int i = 1; i < n; ++i) {
        int c1 = p[i-1] < m, c2 = p[i] < m;
        if(c1 != c2) {
            if(maxlen < lcp[i]) {
                maxlen = lcp[i];
                maxidx = i;
            }
        }
    }
    ans = s.substr(p[maxidx], maxlen);

    cout << ans << '\n';
    return 0;
}