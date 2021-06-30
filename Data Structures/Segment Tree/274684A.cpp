#include<bits/stdc++.h>

using namespace std;

struct node {
    long long v;
};

// SEGMENT TREE WITH SUM OPERATION
class SegmentTree {
    vector<struct node> tree;
    vector<long long> arr;
    struct node nullNode;
    int SIZE;

    struct node single(long long v) {
        return {v};
    }
    struct node merge(struct node a, struct node b) {
        return { a.v + b.v };
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
        nullNode = {0};
        tree = vector<struct node> (SIZE*2 - 1, nullNode);
        buildTree(0, 0, SIZE - 1);
    }
    // Set arr[idx] = v
    void update(int idx, long long v) {
        update(0, 0, SIZE - 1, idx, v);
    }
    // SUM (arr[l], ..., arr[r])
    long long query(int l, int r) {
        return query(0, 0, SIZE - 1, l, r).v;
    }
    // Print the Segment Tree
    void print() {
        for(auto x: tree) {
            cout << x.v << ' ';
        }
        cout << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(i & 1) {
            a[i] = -a[i];
        }
    }
    SegmentTree st(a);
    int m, q, i, j, l, r;
    cin >> m;
    while(m--) {
        cin >> q;
        if(q) {
            cin >> l >> r;
            long long ans = st.query(l-1, r-1);
            if(l & 1) {
                cout << ans << '\n';
            } else {
                cout << -ans << '\n';
            }
        } else {
            cin >> i >> j;
            if(i & 1) {
                st.update(i-1, j);
            } else {
                st.update(i-1, -j);
            }
        }
    }
    return 0;
}