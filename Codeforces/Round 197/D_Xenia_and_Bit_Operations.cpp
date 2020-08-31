//https://codeforces.com/contest/339/problem/D

#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct node {
    /*
        v = velue at node
    */
    T v;
};

int n;


template<typename T>
class SegmentTree {
    private:
        int MAX;
        vector<struct node<T>> tree;
        struct node<T> nullNode;
        vector<T> arr;
        T (*query)(struct node<T>, struct node<T>, int);
        void constructSegmentTree(int root, int l, int r, int type);
        void update(int root, int x, int y, int index, T v, int type);
        struct node<T> queryRange(int root, int x, int y, int l, int r, int type);
    public:
        SegmentTree(vector<T> v, T (*query)(struct node<T> a, struct node<T> b, int type));
        void update(int index, T v);
        T queryRange(int l, int r);
};

template<typename T>
SegmentTree<T>::SegmentTree(vector<T> v, T (*query)(struct node<T> a, struct node<T> b, int type)) {
    this->query = query;
    this->arr = v;
    MAX = (int)pow(2, 1 + ceil(log2(v.size())));
    tree.resize(MAX);
    constructSegmentTree(0, 0, v.size()-1, n&1);
}

template<typename T>
void SegmentTree<T>::constructSegmentTree(int root, int l, int r, int type) {
    if(l == r) {
        tree[root].v = arr[l];
        return;
    }

    constructSegmentTree(root*2+1, l, l + (r-l)/2, type^1);
    constructSegmentTree(root*2+2, l+(r-l)/2 + 1, r, type^1);

    tree[root].v = query(tree[root*2+1], tree[root*2+2], type);
}

template<typename T>
void SegmentTree<T>::update(int index, T v) {
    update(0, 0, arr.size()-1, index, v, n&1);
}

template<typename T>
void SegmentTree<T>::update(int root, int x, int y, int index, T v, int type) {
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
        update(root*2+1, x, mid, index, v, type^1);
    } else {
        update(root*2+2, mid+1, y, index, v, type^1);
    }

    tree[root].v = query(tree[root*2+1], tree[root*2+2], type);
}

template<typename T>
T SegmentTree<T>::queryRange(int l, int r) {
    return queryRange(0, 0, arr.size()-1, l, r, n&1).v;
}

template<typename T>
struct node<T> SegmentTree<T>::queryRange(int root, int x, int y, int l, int r, int type) {
    if(x > r || y < l) {
        return nullNode;
    }

    if(x >= l && y <= r) {
        return tree[root];
    }

    int mid = x + (y-x) / 2;

    struct node<T> left = queryRange(root*2+1, x, mid, l, r, type^1), right = queryRange(root*2+2, mid+1, y, l, r, type^1), tempNode;
    tempNode.v = query(left, right, type);
    return tempNode;
}

// some associative and commutative query function
template<typename T>
T query(struct node<T> a, struct node<T> b, int type) {
    T v;

    if(type & 1)
        v = a.v | b.v;
    else
        v = a.v ^ b.v;

    return v;
}

int main() {
    int m, q, l, r;
    cin >> n >> m;

    int N = pow(2, n);
    vector<int> a(N);
    for(int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    SegmentTree<int> st(a, query);
    
    for(int i = 0; i < m; ++i) {
        cin >> l >> r;
        st.update(l-1, r);
        cout << st.queryRange(0, N-1) << '\n';
    }
    
    return 0;
}