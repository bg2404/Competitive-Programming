#include<bits/stdc++.h>

using namespace std;

struct node {
    long long v;
};

class SegmentTree {
    vector<struct node> tree;
    vector<long long> arr;
    struct node nullNode;
    long long SIZE;

    struct node single(long long v) {
        return {v};
    }
    struct node merge(struct node a, struct node b) {
        return { a.v + b.v };
    }
    void buildTree(long long root, long long x, long long y) {
        if(x == y) {
            if(x < arr.size()) {
                tree[root] = single(arr[x]);
            }
        } else {
            long long m = x + y >> 1;
            buildTree((root<<1)|1, x, m);
            buildTree((root<<1)+2, m+1, y);
            tree[root] = merge(tree[(root<<1)|1], tree[(root<<1)+2]);
        }
    }
    void update(long long root, long long x, long long y, long long idx, long long v) {
        if(x == y) {
            if(x == idx) {
                tree[root] = single(tree[root].v + v);
            }
        } else {
            long long m = x + y >> 1;

            if(idx > m) {
                update((root<<1)+2, m+1, y, idx, v);
            } else {
                update((root<<1)|1, x, m, idx, v);
            }
            tree[root] = merge(tree[(root<<1)|1], tree[(root<<1)+2]);
        }
    }
    struct node query(long long root, long long x, long long y, long long l, long long r) {
        if(y < l || r < x) {
            return nullNode;
        }
        if(x >= l && y <= r) {
            return tree[root];
        }
        long long m = x + y >> 1;
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
    void update(long long idx, long long v) {
        update(0, 0, SIZE - 1, idx, v);
    }
    // MAX (arr[l], ..., arr[r])
    long long query(long long l, long long r) {
        return query(0, 0, SIZE - 1, l, r).v;
    }
    // Print the Segment Tree
    void print() {
        for(auto x: tree) {
            cout << x.v << ' ';
        }
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m, q, l, r, v, i;
    cin >> n >> m;
    vector<long long> a(n+1, 0);
    SegmentTree st(a);
    while(m--) {
        cin >> q;
        if(q == 1) {
            cin >> l >> r >> v;
            st.update(l, v);
            st.update(r, -v);
        } else {
            cin >> i;
            cout << st.query(0, i) << '\n';
        }
    }
    return 0;
}