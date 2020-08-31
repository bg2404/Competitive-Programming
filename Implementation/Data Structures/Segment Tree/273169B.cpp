// Attempt 1 - Successful (Without Copy and Paste)

#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct node {
    T v; // value at node
};


template<typename T>
class SegmentTree {
    private:
        int MAX;
        vector<struct node<T>> tree;
        struct node<T> nullNode;
        vector<T> arr;
        T (*query)(struct node<T>, struct node<T>);
        void constructSegmentTree(int root, int l, int r);
        void update(int root, int x, int y, int index, T v);
        struct node<T> queryRange(int root, int x, int y, int l, int r);
    public:
        SegmentTree(vector<T> v, T (*query)(struct node<T> a, struct node<T> b));
        void update(int index, T v);
        T queryRange(int l, int r);
        void print() {
            for(auto x: tree) {
                cout << x.v << ' ';
            }
            cout << '\n';
        }
};

template<typename T>
SegmentTree<T>::SegmentTree(vector<T> v, T (*query)(struct node<T> a, struct node<T> b)) {
    this->query = query;
    this->arr = v;
    MAX = (int)pow(2, 1 + ceil(log2(v.size())));
    tree.resize(MAX);
    nullNode.v = INT_MAX;
    constructSegmentTree(0, 0, v.size()-1);
}

template<typename T>
void SegmentTree<T>::constructSegmentTree(int root, int l, int r) {
    if(l == r) {
        tree[root].v = arr[l];
        return;
    }

    constructSegmentTree(root*2+1, l, l + (r-l)/2);
    constructSegmentTree(root*2+2, l+(r-l)/2 + 1, r);

    tree[root].v = query(tree[root*2+1], tree[root*2+2]);
}

template<typename T>
void SegmentTree<T>::update(int index, T v) {
    update(0, 0, arr.size()-1, index, v);
}

template<typename T>
void SegmentTree<T>::update(int root, int x, int y, int index, T v) {
    if(x > y) {
        return;
    }
    if(x == y) {
        if(x == index) {
            tree[root].v = v;
        }
        return;
    }

    int mid = x + (y-x)/2;

    if(mid >= index) {
        update(root*2+1, x, mid, index, v);
    } else {
        update(root*2+2, mid+1, y, index, v);
    }

    tree[root].v = query(tree[root*2+1], tree[root*2+2]);
}

template<typename T>
T SegmentTree<T>::queryRange(int l, int r) {
    return queryRange(0, 0, arr.size()-1, l, r).v;
}

template<typename T>
struct node<T> SegmentTree<T>::queryRange(int root, int x, int y, int l, int r) {
    if(x > r || y < l) {
        return nullNode;
    }

    if(x >= l && y <= r) {
        return tree[root];
    }

    int mid = x + (y-x) / 2;

    struct node<T> left = queryRange(root*2+1, x, mid, l, r), right = queryRange(root*2+2, mid+1, y, l, r), tempNode;
    tempNode.v = query(left, right);
    return tempNode;
}

// some associative and commutative query function
template<typename T>
T query(struct node<T> a, struct node<T> b) {
    T v;
    // Sum Query
    // v = a.v + b.v;

    // Min Query
    v = min(a.v, b.v);

    // Max Query
    // v = max(a.v, b.v);

    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q, l, r;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    SegmentTree<int> st(a, query);

    for(int i = 0; i < m; ++i) {
        // st.print();
        cin >> q >> l >> r;
        if(q == 1) {
            st.update(l, r);
        } else {
            cout << st.queryRange(l, r-1) << '\n';
        }
    }
    // st.print();

    return 0;
}