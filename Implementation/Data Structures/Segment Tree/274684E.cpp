#include <bits/stdc++.h>

using namespace std;

struct node {
    long long v = INT_MAX;
};

// MIN SEGMENT TREE
class SegmentTree {
    vector<struct node> tree;
    vector<long long> arr;
    struct node nullNode;
    long long SIZE;

    struct node single(long long v) {
        return {v};
    }
    struct node merge(struct node a, struct node b) {
        return { min(a.v, b.v) };
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
                tree[root] = single(v);
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
    long long earthquake(long long root, long long x, long long y, long long l, long long r, long long p) {
        if(tree[root].v > p) {
            return 0;
        }
        if(x == y) {
            tree[root] = single(INT_MAX);
            return 1;
        }
        long long m = x + y >> 1;
        long long ans = earthquake(root*2+1, x, m, l, r, p) + earthquake(root*2+2, m+1, y, l, r, p);
        tree[root] = merge(tree[(root<<1)|1], tree[(root<<1)+2]);
        return ans;
    }
public:
    SegmentTree(vector<long long> arr) {
        this->arr = arr;
        SIZE = pow(2, 1 + floor(log2(arr.size())));
        nullNode = {INT_MAX};
        tree = vector<struct node> (SIZE*2 - 1, nullNode);
        buildTree(0, 0, SIZE - 1);
    }
    // Set arr[idx] = v
    void update(long long idx, long long v) {
        update(0, 0, SIZE - 1, idx, v);
    }
    // Buildings Demolished between l and r by an earthquake with power p;
    long long earthquake(long long l, long long r, long long p) {
        return earthquake(0, 0, SIZE - 1, l, r, p);
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
    long long n, m, q, i, h, l, r, p;
    cin >> n >> m;
    SegmentTree st(vector<long long> (n, INT_MAX));
    while(m--) {
        cin >> q;
        if(q == 1) {
            cin >> i >> h;
            st.update(i, h);
        } else {
            cin >> l >> r >> p;
            cout << st.earthquake(l, r-1, p) << '\n';
        }
    }

    return 0;
}