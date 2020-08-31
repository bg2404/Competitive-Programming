#include<bits/stdc++.h>

using namespace std;

class SparseTable {
    vector<int> arr;
    vector<vector<int> > sparse;
public:
    SparseTable() {}
    SparseTable(vector<int> &a);
    int queryRange(int l, int r);
};

SparseTable::SparseTable(vector<int> &a) {
    int n = a.size(), m = log2(n) + 1;
    arr = a;
    sparse = vector<vector<int> > (n, vector<int> (m, -1));
    for(int i = 0; i < n; ++i) sparse[i][0] = i;

    for(int j = 1; j < m; ++j) {
        for(int i = 0; i + (1 << j) <= n; ++i) {
            if(arr[sparse[i][j-1]] < arr[sparse[i + (1 << (j-1))][j-1]]) {
                sparse[i][j] = sparse[i][j-1];
            } else {
                sparse[i][j] = sparse[i + (1 << (j-1))][j-1];
            }
        }
    }
}

int SparseTable::queryRange(int l, int r) {
    int len = r - l + 1, k = log2(len), rem = len - (1 << k);
    return min(arr[sparse[l][k]], arr[sparse[l + rem][k]]);
}

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

vector<int> suffix_array(string &s, vector<int> &p, vector<int> &c) {
    s.push_back(' ');
    int n = s.size();
    p = c = vector<int>(n);
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
    return p;
}

vector<int> p, c, lcp;
SparseTable st;

bool comparator(const pair<int, int> &a, const pair<int, int> &b) {
    int x1 = a.first, x2 = b.first, y1 = a.second, y2 = b.second;
    if(x1 == x2) {
        return y1 < y2;
    }
    int l1 = a.second - a.first + 1, l2 = b.second - b.first + 1;
    int k = (c[x1] < c[x2]) ? st.queryRange(c[x1] + 1, c[x2]): st.queryRange(c[x2] + 1, c[x1]);

    if(l1 == l2) {
        if(k >= l1) {
            return x1 < x2;
        }
        return c[x1] < c[x2];
    }
    if(k >= l1 || k >= l2) {
        return l1 < l2;
    }
    return c[x1 + k] < c[x2 + k];
}

int main() {
    string s;
    cin >> s;
    int n, m, k = 0;
    cin >> n;
    vector<pair<int, int> > substrings(n);
    for(int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        substrings[i] = {l - 1, r - 1};
    }
    suffix_array(s, p, c);
    m = s.size();
    lcp = vector<int>(m, 0);
    k = 0;
    for(int i = 0; i + 1 < m; ++i) {
        int pi = c[i];
        int j = p[pi - 1];
        while(i + k < m && j + k < m && s[i + k] == s[j + k]) ++k;
        lcp[pi] = k;
        k = max(k-1, 0);
    }

    // for(int i = 0; i < m; ++i) {
    //     cout << c[i] << " " << p[i] << " " << s.substr(p[i], m - p[i]) << endl;
    // }

    st = SparseTable(lcp);
    sort(substrings.begin(), substrings.end(), comparator);
    for(auto s: substrings) {
        cout << s.first + 1 << ' ' << s.second + 1 << '\n';
    }
    return 0;
}