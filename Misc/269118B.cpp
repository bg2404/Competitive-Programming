#include<bits/stdc++.h>

using namespace std;

vector<int> suffix_array(string s) {
    s.push_back('$');
    int n = s.size();
    vector<int> p(n), c(n);
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

int lower_bound(const string &s, const vector<int> &p, const string &t) {
    int a = s.size(), b = t.size();
    int l = 0, r = a - 1, m;
    int ans = -1;
    while(l <= r) {
        m = (l + r) / 2;
        string q = s.substr(p[m], min(b, a - p[m]));
        if(q == t) {
            ans = m;
            r = m - 1;
        } else if(q < t) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans;
}

int upper_bound(const string &s, const vector<int> &p, const string &t) {
    int a = s.size(), b = t.size();
    int l = 0, r = a - 1, m;
    int ans = -1;
    while(l <= r) {
        m = (l + r) / 2;
        string q = s.substr(p[m], min(b, a - p[m]));
        if(q == t) {
            ans = m;
            l = m + 1;
        } else if(q < t) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    vector<int> p = suffix_array(s);
    s.push_back('$');
    int q;
    cin >> q;
    while(q--) {
        string t;
        cin >> t;
        int l = lower_bound(s, p, t);
        if(l == -1) {
            cout << 0 << '\n';
        } else {
            int r = upper_bound(s, p, t);
            cout << r - l + 1 << '\n';
        }
    }
    return 0;
}