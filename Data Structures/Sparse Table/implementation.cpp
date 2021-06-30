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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) {
        cin >> x;
    }
    SparseTable st(a);
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << st.queryRange(l-1, r-1) << '\n';
    }
    return 0;
}