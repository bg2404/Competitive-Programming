#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    s.push_back('$');
    int n = s.size();
    vector<int> p(n), c(n);
    {
        // k = 0
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

    vector<int> lcp(n);
    k = 0;
    for(int i = 0; i + 1 < n; ++i) {
        int pi = c[i];
        int j = p[pi - 1];
        while(s[i+k] == s[j+k] && i + k < n && j + k < n) ++k;
        lcp[pi] = k;
        k = max(0, k - 1);
    }

    for(int i = 0; i < n; ++i) {
        cout << lcp[i] << " " << p[i] << " " << s.substr(p[i], n - p[i]) << endl;
    }
    return 0;
}