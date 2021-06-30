#include <bits/stdc++.h>

using namespace std;

struct node {
    long long inv;
    vector<long long> cnt;
    node() {
        inv = 0;
        cnt = vector<long long>(41, 0);
    }
    node(int x) {
        inv = 0;
        cnt = vector<long long>(41, 0);
        cnt[x] = 1;
    }
    node(long long inv, vector<long long> cnt) {
        this->inv = inv;
        this->cnt = cnt;
    }
};

class SegmentTree {
    vector<struct node> tree;
    vector<long long> arr;
    struct node nullNode;
    int SIZE;

    struct node single(int v) {
        return node(v);
    }
    struct node merge(struct node a, struct node b) {
        long long inv = a.inv + b.inv, pre = 0;
        for(int i = 39; i>= 0; --i) {
            pre += a.cnt[i+1];
            inv += b.cnt[i]*pre;
        }
        vector<long long> cnt(41);
        for(int i = 0; i < 41; ++i) {
            cnt[i] = a.cnt[i] + b.cnt[i];
        }
        return node(inv, cnt);
    }
    void buildTree(int root, int x, int y) {
        if(x == y) {
            if(x < arr.size()) {
                tree[root] = single(arr[x]);
            }
        } else {
            int m = x + y >> 1;
            buildTree((root<<1)|1, x, m);
            buildTree((root<<1)+2, m+1, y);
            tree[root] = merge(tree[(root<<1)|1], tree[(root<<1)+2]);
        }
    }
    void update(int root, int x, int y, int idx, long long v) {
        if(x == y) {
            if(x == idx) {
                tree[root] = single(v);
            }
        } else {
            int m = x + y >> 1;

            if(idx > m) {
                update((root<<1)+2, m+1, y, idx, v);
            } else {
                update((root<<1)|1, x, m, idx, v);
            }
            tree[root] = merge(tree[(root<<1)|1], tree[(root<<1)+2]);
        }
    }
    struct node query(int root, int x, int y, int l, int r) {
        if(y < l || r < x) {
            return nullNode;
        }
        if(x >= l && y <= r) {
            return tree[root];
        }
        int m = x + y >> 1;
        return merge(query(root<<1|1, x, m, l, r), query((root<<1)+2, m+1, y, l, r));
    }
public:
    SegmentTree(vector<long long> arr) {
        this->arr = arr;
        SIZE = pow(2, 1 + floor(log2(arr.size())));
        nullNode = node();
        tree = vector<struct node> (SIZE*2 - 1, nullNode);
        buildTree(0, 0, SIZE - 1);
    }
    // Set arr[idx] = v
    void update(int idx, long long v) {
        update(0, 0, SIZE - 1, idx, v);
    }
    // MAX (arr[l], ..., arr[r])
    long long query(int l, int r) {
        return query(0, 0, SIZE - 1, l, r).inv;
    }
    // Print the Segment Tree
    void print() {
        for(auto x: tree) {
            cout << x.inv << ' ';
        }
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<long long> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        --v[i];
    }
    SegmentTree st(v);
    while(q--) {
        int t, x, y;
        cin >> t >> x >> y;
        --x; --y;
        if(t == 1) {
            cout << st.query(x, y) << '\n';
        } else {
            st.update(x, y);
        }
    }

    return 0;
}