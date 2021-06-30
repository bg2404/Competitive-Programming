#include<bits/stdc++.h>
#define MOD 1000000009

using namespace std;

vector<int> fib, a;

class SegmentTree {
    private:
        int MAX;
        vector<int> tree;
        vector<pair<int, int> > lazy_tree;
        vector<int> arr;
        void constructSegmentTree(int root, int l, int r);
        void update(int root, int x, int y, int l, int r);
        void lazyShift(int root, int l, int r);
        int queryRange(int root, int x, int y, int l, int r);
    public:
        SegmentTree(vector<int> v);
        void update(int l, int r);
        int queryRange(int l, int r);
        void printTree() {
            for(auto x: tree) {
                cout << x << ' ';
            }
            cout << '\n';
        }
};

SegmentTree::SegmentTree(vector<int> v) {
    this->arr = v;
    MAX = (int)pow(2, 1 + ceil(log2(v.size())));
    tree.resize(MAX);
    lazy_tree = vector<pair<int, int> >(MAX, {0, 0});
    constructSegmentTree(0, 0, v.size()-1);
}

void SegmentTree::constructSegmentTree(int root, int l, int r) {
    if(l == r) {
        tree[root] = arr[l];
        return;
    }

    constructSegmentTree(root*2+1, l, l + (r-l)/2);
    constructSegmentTree(root*2+2, l+(r-l)/2 + 1, r);

    tree[root] = (tree[root*2+1] + tree[root*2+2]) % MOD;
}

void SegmentTree::lazyShift(int root, int l, int r) {
    if((lazy_tree[root].first == 0 && lazy_tree[root].second == 0) || l > r) {
        return;
    }
    int f = lazy_tree[root].first, s = lazy_tree[root].second;
    tree[root] += fib[s + 2] - fib[f + 1];
    tree[root] %= MOD;
    if(l != r) {
        int m = f + s >> 1;
        lazyShift(root<<1|1, l, l + r >> 1);
        lazyShift((root<<1)+2, (l + r >> 1) + 1, r);
        lazy_tree[root<<1|1] = {f, m};
        lazy_tree[(root<<1)+2] = {m+1, s};
    }
    lazy_tree[root] = {0, 0};
}

void SegmentTree::update(int l, int r) {
    update(0, 0, arr.size()-1, l, r);
}

void SegmentTree::update(int root, int x, int y, int l, int r) {
    if(x > y || l > r) {
        return;
    }
    lazyShift(root, x, y);
    if(r < x || y < l) {
        return;
    }
    int m = (x + y) / 2;
    if(l<= x && r >= y) {
        tree[root] += fib[y + 2] - fib[x + 1];
        tree[root] %= MOD;
        if(x != y) {
            lazyShift(root<<1|1, l, l + r >> 1);
            lazyShift((root<<1)+2, (l + r >> 1) + 1, r);
            lazy_tree[root<<1|1] = {x, m};
            lazy_tree[(root<<1)+2] = {m+1, y};
        }
    } else {
        update(root<<1|1, x, m, l, r);
        update((root<<1)+2, m+1, y, l, r);
        tree[root] = (tree[root<<1|1] + tree[(root<<1)+2]) % MOD;
    }
}

int SegmentTree::queryRange(int l, int r) {
    return queryRange(0, 0, arr.size()-1, l, r);
}

int SegmentTree::queryRange(int root, int x, int y, int l, int r) {
    if(x > y || l > r) {
        return INT_MIN;
    }
    if(x > r || y < l) {
        return INT_MIN;
    }

    lazyShift(root, x, y);
    if(x >= l && y <= r) {
        return tree[root];
    }

    int mid = (x + y) >> 1;

    return (queryRange(root<<1|1, x, mid, l, r) + queryRange((root<<1)+2, mid+1, y, l, r)) % MOD;
}

void fibonacci(int n) {
    fib = vector<int>(n+1, 0);
    fib[1] = 1;
    for(int i = 2; i <= n; ++i) {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    fibonacci(n);
    a = vector<int>(n+1, -1);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    SegmentTree st(a);
    while(m--) {
        int q, l, r;
        cin >> q >> l >> r;
        if(q == 1) {
            st.update(l, r);
        } else {
            cout << st.queryRange(l, r) << '\n';
        }
    }

    return 0;
}