#include<bits/stdc++.h>

using namespace std;

struct node {
    int v;
};

class SegmentTree {
    vector<struct node> tree;
    vector<int> arr;
    struct node nullNode;
    int SIZE;

    struct node single(int v) {
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
public:
    SegmentTree(vector<int> arr) {
        this->arr = arr;
        SIZE = pow(2, 1 + floor(log2(arr.size())));
        nullNode = {0};
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
    int n;
    cin >> n;
    vector<int> a(n<<1), v(n<<1, 0), left(n+1, -1), right(n+1, -1), ans(n+1, 0);
    for(int i = 0; i < (n<<1); ++i) {
        cin >> a[i];
        (left[a[i]] == -1) ? left[a[i]] = i : right[a[i]] = i;
    }
    SegmentTree st(v);
    for(int i = 0; i < (n<<1); ++i) {
        if(i == left[a[i]]) {
            st.update(i, 1);
        } else {
            st.update(left[a[i]], 0);
            ans[a[i]] = st.query(left[a[i]], right[a[i]]);
        }
    }
    for(int i = (n << 1) - 1; i >= 0; --i) {
        if(i == right[a[i]]) {
            st.update(i, 1);
        } else {
            st.update(right[a[i]], 0);
            ans[a[i]] += st.query(left[a[i]], right[a[i]]);
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}