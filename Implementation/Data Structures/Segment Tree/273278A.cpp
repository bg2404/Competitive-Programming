// Attempt 1 - Successful (Without Copy and Paste)

#include <bits/stdc++.h>

using namespace std;

struct node {
    long long mss; // value at node
    long long pref;
    long long suf;
    long long sum;
};



// Update node, nullNode, query and single element initialization
class SegmentTree {
    private:
        int MAX;
        vector<struct node> tree;
        struct node nullNode;
        vector<long long> arr;
        struct node query(struct node, struct node);
        void constructSegmentTree(int root, int l, int r);
        void update(int root, int x, int y, int index, long long v);
        struct node queryRange(int root, int x, int y, int l, int r);
    public:
        SegmentTree(vector<long long> v);
        void update(int index, long long v);
        long long queryRange(int l, int r);
};

SegmentTree::SegmentTree(vector<long long> v) {
    this->arr = v;
    MAX = (int)pow(2, 1 + ceil(log2(v.size())));
    tree.resize(MAX);
    nullNode = {INT64_MIN, INT64_MIN, INT64_MIN, INT64_MIN};
    constructSegmentTree(0, 0, v.size()-1);
}

void SegmentTree::constructSegmentTree(int root, int l, int r) {
    if(l == r) {
        tree[root] = {max(0LL, arr[l]), arr[l], arr[l], arr[l]};
        return;
    }

    constructSegmentTree(root*2+1, l, l + (r-l)/2);
    constructSegmentTree(root*2+2, l+(r-l)/2 + 1, r);

    tree[root] = query(tree[root*2+1], tree[root*2+2]);
}

void SegmentTree::update(int index, long long v) {
    update(0, 0, arr.size()-1, index, v);
}

void SegmentTree::update(int root, int x, int y, int index, long long v) {
    if(x > y) {
        return;
    }
    if(x == y) {
        if(x == index) {
            tree[root] = {max(0LL, v), v, v, v};
        }
        return;
    }

    int mid = x + (y-x)/2;

    if(mid >= index) {
        update(root*2+1, x, mid, index, v);
    } else {
        update(root*2+2, mid+1, y, index, v);
    }

    tree[root] = query(tree[root*2+1], tree[root*2+2]);
}

long long SegmentTree::queryRange(int l, int r) {
    return queryRange(0, 0, arr.size()-1, l, r).mss;
}

struct node SegmentTree::queryRange(int root, int x, int y, int l, int r) {
    if(x > r || y < l) {
        return nullNode;
    }

    if(x >= l && y <= r) {
        return tree[root];
    }

    int mid = x + (y-x) / 2;

    struct node left = queryRange(root*2+1, x, mid, l, r), right = queryRange(root*2+2, mid+1, y, l, r), tempNode;
    tempNode = query(left, right);
    return tempNode;
}

// some associative query function
struct node SegmentTree::query(struct node a, struct node b) {
    long long mss, pref, suf, sum;
    sum = a.sum + b.sum;
    suf = max(a.suf + b.sum, b.suf);
    pref = max(a.pref, a.sum + b.pref);
    mss = max(a.suf + b.pref, max(a.mss, b.mss));
    return {mss, pref, suf, sum};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x, v;
    cin >> n >> m;

    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    SegmentTree st(a);
    cout << st.queryRange(0, n-1) << '\n';
    for(int i = 0; i < m; ++i) {
        cin >> x >> v;
        st.update(x, v);
        cout << st.queryRange(0, n-1) << '\n';
    }

    return 0;
}