// Attempt 1 - Successful (Without Copy and Paste)

#include <bits/stdc++.h>

using namespace std;

struct node {
    int v;
};

// MAX SEGMENT TREE
class SegmentTree {
    vector<struct node> tree;
    vector<int> arr;
    struct node nullNode;
    int SIZE;

    struct node single(int v) {
        return {v};
    }
    struct node merge(struct node a, struct node b) {
        return { max(a.v, b.v) };
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
    void update(int root, int x, int y, int idx, int v) {
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
    int firstGreater(int root, int x, int y, int v, int l) {
        if(y < l) {
            return -1;
        }
        if(x == y) {
            if(x < arr.size() && tree[root].v >= v) {
                return x;
            }
            return -1;
        }
        if(tree[root].v < v) {
            return -1;
        }
        int m = x + y >> 1;
        int left = firstGreater((root<<1)|1, x, m, v, l);
        if(left >= 0) {
            return left;
        }
        return firstGreater((root<<1)+2, m + 1, y, v, l);
    }
public:
    SegmentTree(vector<int> arr) {
        this->arr = arr;
        SIZE = pow(2, 1 + floor(log2(arr.size())));
        nullNode = {INT_MIN};
        tree = vector<struct node> (SIZE*2 - 1, nullNode);
        buildTree(0, 0, SIZE - 1);
    }
    // Set arr[idx] = v
    void update(int idx, int v) {
        update(0, 0, SIZE - 1, idx, v);
    }
    // MAX (arr[l], ..., arr[r])
    int query(int l, int r) {
        return query(0, 0, SIZE - 1, l, r).v;
    }
    // MIN j such that (j >= l and arr[j] >= v)
    int firstGreater(int v, int l) {
        return firstGreater(0, 0, SIZE - 1, v, l);
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
    int n, m, q, l, r, idx, v;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    SegmentTree st(a);

    for(int i = 0; i < m; ++i) {
        cin >> q ;
        if(q == 1) {
            cin >> idx >> v;
            st.update(idx - 1, v);
        } else {
            cin >> l >> r;
            cout << st.query(l-1, r-1) << '\n';
        }
    }

    return 0;
}