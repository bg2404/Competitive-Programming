#include<bits/stdc++.h>

using namespace std;

long long n, m, k;

struct bot {
    vector<long long> d;
    bot() {
        d = vector<long long>();
    }
    bot(long long m) {
        d = vector<long long> (m, 0);
    }
    bot(vector<long long> v) {
        d = v;
    }
    long long sum() {
        long long s = 0;
        for(int i = 0; i < m; ++i) {
            s += d[i];
        }
        return s;
    }
};

bot merge(bot a, bot b) {
    vector<long long> v(m);
    for(long long i = 0; i < m; ++i) {
        v[i] = max(a.d[i], b.d[i]);
    }
    return {v};
}

vector<vector<bot> > sparseTable;

void buildSparseTable(vector<bot> v) {
    long long n = v.size(), m = 1 + log2(n);
    sparseTable = vector<vector<bot> > (n, vector<bot> (m));
    for(long long i = 0; i < n; ++i) {
        sparseTable[i][0] = v[i];
    }
    for(long long j = 1; j < m; ++j) {
        for(long long i = 0; i + (1 << j) <= n; ++i) {
            sparseTable[i][j] = merge(sparseTable[i][j-1], sparseTable[i + (1 << (j-1))][j-1]);
        }
    }
}

bot query(long long &l, long long &r) {
    if(l > r) {
        r = l;
    }
    long long len = r - l + 1, k = log2(len), rem = ( 1<<k ) - 1;
    return merge(sparseTable[l][k], sparseTable[r - rem][k]);
}

int main() {
    cin >> n >> m >> k;
    vector<bot> v(n);
    for(long long i = 0; i < n; ++i) {
        vector<long long> b(m);
        for(long long j = 0; j < m; ++j) {
            cin >> b[j];
        }
        v[i] = {b};
    }
    buildSparseTable(v);
    long long l = 0, r = 0;
    long long ml = 0;
    bot ans(vector<long long>(m, 0));
    while(r < n && l < n) {
        bot mb = query(l, r);
        long long sum = mb.sum();
        if(sum <= k) {
            if(ml < r - l + 1) {
                ml = r - l + 1;
                ans = mb;
            }
            ++r;
        } else {
            ++l;
        }
    }
    for(int i = 0; i < m; ++i) {
        cout << ans.d[i] << ' ';
    }
    cout << '\n';
    return 0;
}