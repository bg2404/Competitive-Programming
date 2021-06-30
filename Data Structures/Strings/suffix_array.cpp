#include<bits/stdc++.h>

using namespace std;

void count_sort(vector<int> &p, vector<int> &c) {
    int n = p.size();
    vector<int> count(n);
    for(auto x: c) {
        ++count[x];
    }
    vector<int> pos(n);
    pos[0] = 0;
    for(int i = 1; i < n; ++i) {
        pos[i] = pos[i-1] + count[i-1];
    }
    vector<int> p_new(n);
    for(auto x: p) {
        int i = c[x];
        p_new[pos[i]] = x;
        ++pos[i];
    }
    p = p_new;
}

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
        for(int i = 0; i < n; ++i) {
            p[i] = (p[i] - (1 << k) + n) % n;
        }

        count_sort(p, c);

        vector<int> c_new(n);

        c_new[p[0]] = 0;
        for(int i = 1; i < n; ++i) {
            pair<int, int> prev = {c[p[i-1]], c[((p[i-1] + (1 << k)) % n)]};
            pair<int, int> now  = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            c_new[p[i]] = c_new[p[i-1]] + (prev != now);
        }
        c = c_new;
        ++k;
    }

    for(int i = 0; i < n; ++i) {
        cout << p[i] << " \n"[i + 1 == n];
    }
    return 0;
}