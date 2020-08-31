#include<bits/stdc++.h>

using namespace std;

template<typename T>
struct NODE {
    T v;
};

/*
Array indexing must be 0-based (Acc. to Implementation).
Query 1: Add v to a[i]
Query 2: Sum a[0] to a[i]
*/
template<typename T>
class FenwickTree {
    vector<NODE<T> > tree;
    vector<T> arr;
    NODE<T> nullNode;
    NODE<T> single(T v) {
        return {v};
    }
    NODE<T> merge(NODE<T> a, NODE<T> b) {
        return {a.v + b.v};
    }
public:
    FenwickTree() {
        nullNode = {0};
        tree = vector<NODE<T> >();
    }
    FenwickTree(int n) {
        nullNode = {0};
        tree = vector<NODE<T> >(n+1, nullNode);
        arr = vector<T> (n);
    }
    FenwickTree(vector<T> v) {
        nullNode = {0};
        tree = vector<NODE<T> >(v.size() + 1, nullNode);
        arr = v;
        for(int i = 1; i < tree.size(); ++i) {
            tree[i] = merge(tree[i], single(v[i-1]));
            int p = i + (i & -i);
            if(p < tree.size()) {
                tree[p] = merge(tree[p], tree[i]);
            }
        }
    }
    void increase(int i, T v) {
        arr[i] += v;
        for(int p = i+1; p < tree.size(); p += (p & -p)) {
            tree[p] = merge(tree[p], single(v));
        }
    }
    void update(int i, T v) {
        T inc = v - arr[i];
        increase(i, inc);
    }

    T query(int i) {
        NODE<T> ans = nullNode;
        for(int p = i + 1; p; p -= (p & -p)) {
            ans = merge(ans, tree[p]);
        }
        return ans.v;
    }
    T query(int l, int r) {
        return query(r) - query(l-1);
    }
    void print() {
        for(int i = 0; i < tree.size(); ++i) {
            cout << tree[i].v << ' ';
        }
        cout << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    FenwickTree<long long> ft(a);
    while(m--) {
        int q;
        cin >> q;
        if(q == 1) {
            int i, v;
            cin >> i >> v;
            ft.update(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << ft.query(l, r-1) << '\n';
        }
    }
    return 0;
}