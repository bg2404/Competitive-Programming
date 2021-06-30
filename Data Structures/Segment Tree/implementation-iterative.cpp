// Attempt 1 - Successful (Without Copy and Paste)

#include <bits/stdc++.h>

using namespace std;


template<typename T>
class SegmentTree {
    private:
        int n;
        vector<T> tree;
        vector<T> arr;
    public:
        SegmentTree(vector<T> v);
        void update(int index, T v);
        T queryRange(int l, int r);
};

template<typename T>
SegmentTree<T>::SegmentTree(vector<T> v) {
    this->arr = v;
    n = v.size();
    tree.resize(2*n);
    for(int i = 0; i < n; ++i) {
        tree[i + n] = v[i];
    }
    for(int i = n - 1; i > 0; --i) {
        tree[i] = max(tree[i<<1], tree[i<<1|1]);
    }

    for(auto x: tree) {
        cout << x << ' ';
    }
    cout << '\n';
}

template<typename T>
void SegmentTree<T>::update(int index, T value) {
    for(tree[index += n] = value; index > 1; index >>= 1) {
        tree[index >> 1] = max(tree[index], tree[index ^ 1]);
    }
    for(auto x: tree) {
        cout << x << ' ';
    }
    cout << '\n';
}

template<typename T>
T SegmentTree<T>::queryRange(int l, int r) { //[l, r)
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l & 1) res = max(res,tree[l++]);
        if(r & 1) res = max(res, tree[--r]);
    }
    return res;
}

int main() {
    int n, m, q, l, r;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    SegmentTree<int> st(a);

    for(int i = 0; i < m; ++i) {
        cin >> q >> l >> r;
        if(q == 1) {
            st.update(l-1, r);
        } else {
            cout << st.queryRange(l-1, r) << '\n';
        }
    }

    return 0;
}