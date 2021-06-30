// Attempt 1 - Successful (Without Copy and Paste)

#include <bits/stdc++.h>

using namespace std;

struct node {
    int v = 0; // value at node
};

// Segment Tree with min/max query and increment update on intervals
class SegmentTree {
    private:
        int MAX;
        vector<struct node> tree;
        vector<int> lazy_tree;
        struct node null_node;
        vector<int> arr;
        int (*query)(struct node, struct node);
        void constructSegmentTree(int root, int l, int r);
        void update(int root, int x, int y, int l, int r, int v);
        void lazyShift(int root, int l, int r);
        struct node queryRange(int root, int x, int y, int l, int r);
    public:
        SegmentTree(vector<int> v, int (*query)(struct node a, struct node b));
        void update(int l, int r, int v);
        int queryRange(int l, int r);
        void printTree() {
            for(auto x: tree) {
                cout << x.v << ' ';
            }
            cout << '\n';
        }
};

SegmentTree::SegmentTree(vector<int> v, int (*query)(struct node a, struct node b)) {
    this->query = query;
    this->arr = v;
    MAX = (int)pow(2, 1 + ceil(log2(v.size())));
    tree.resize(MAX);
    null_node.v = 1e9;
    lazy_tree = vector<int>(MAX, 0);
    constructSegmentTree(0, 0, v.size()-1);
}

void SegmentTree::constructSegmentTree(int root, int l, int r) {
    if(l == r) {
        tree[root].v = arr[l];
        return;
    }

    constructSegmentTree(root*2+1, l, l + (r-l)/2);
    constructSegmentTree(root*2+2, l+(r-l)/2 + 1, r);

    tree[root].v = query(tree[root*2+1], tree[root*2+2]);
}

void SegmentTree::lazyShift(int root, int l, int r) {
    if(lazy_tree[root] == 0 || l > r) {
        return;
    }
    tree[root].v += lazy_tree[root];
    if(l != r) {
        lazy_tree[root<<1|1] += lazy_tree[root];
        lazy_tree[(root<<1)+2] += lazy_tree[root];
    }
    lazy_tree[root] = 0;
}

void SegmentTree::update(int l, int r, int v) {
    update(0, 0, arr.size()-1, l, r, v);
}

void SegmentTree::update(int root, int x, int y, int l, int r, int v) {
    if(x > y || l > r) {
        return;
    }
    if(r < x || y < l) {
        return;
    }
    lazyShift(root, x, y);
    int m = (x + y) / 2;
    if(l<= x && r >= y) {
        tree[root].v += v;
        if(x != y) {
            lazy_tree[root<<1|1] += v;
            lazy_tree[(root<<1)+2] += v;
        }
    } else {
        update(root<<1|1, x, m, l, r, v);
        update((root<<1)+2, m+1, y, l, r, v);
        tree[root].v = query(tree[root<<1|1], tree[(root<<1)+2]);
    }
}

int SegmentTree::queryRange(int l, int r) {
    return queryRange(0, 0, arr.size()-1, l, r).v;
}

struct node SegmentTree::queryRange(int root, int x, int y, int l, int r) {
    if(x > y || l > r) {
        return null_node;
    }
    if(x > r || y < l) {
        return null_node;
    }

    lazyShift(root, x, y);
    if(x >= l && y <= r) {
        return tree[root];
    }

    int mid = (x + y) >> 1;

    struct node left = queryRange(root*2+1, x, mid, l, r), right = queryRange(root*2+2, mid+1, y, l, r), tempNode;
    tempNode.v = query(left, right);
    return tempNode;
}

// some associative and commutative query function
int query(struct node a, struct node b) {
    int v;
    // // Sum Query
    // v = a.v + b.v;

    // Min Query
    v = min(a.v, b.v);

    // // Max Query
    // v = max(a.v, b.v);

    return v;
}

int main() {
    int n, m, q, l, r;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    SegmentTree st(a, query);
    st.printTree();
    for(int i = 0; i < m; ++i) {
        cin >> q >> l >> r;
        if(q == 1) {
            int v;
            cin >> v;
            st.update(l-1, r-1, v);
        } else {
            cout << st.queryRange(l-1, r-1) << '\n';
        }
        st.printTree();
    }

    return 0;
}