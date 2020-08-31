#include<bits/stdc++.h>

using namespace std;

int r;
int i = 0;
struct matrix {
    int a, b, c, d;
    void init(int a, int b, int c, int d) {
        this->a = a % r;
        this->b = b % r;
        this->c = c % r;
        this->d = d % r;
    }
    matrix() {
        init(0, 0, 0, 0);
    }
    matrix(int a, int b, int c, int d) {
        init(a, b, c, d);
    }

    matrix operator*(const matrix &o) const {
        return {(a*o.a + b*o.c) % r, (a*o.b + b*o.d) % r, (c*o.a + d*o.c) % r, (c*o.b + d*o.d) % r};
    }
};

struct node {
    matrix v;
};

// SEGMENT TREE WITH MATRIX MULTIPLACATION
class SegmentTree {
    vector<struct node> tree;
    vector<matrix> arr;
    struct node nullNode;
    int SIZE;

    struct node single(matrix v) {
        return {v};
    }
    struct node merge(struct node a, struct node b) {
        return { a.v * b.v };
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
    SegmentTree(vector<matrix> arr) {
        this->arr = arr;
        SIZE = pow(2, 1 + floor(log2(arr.size())));
        nullNode = {matrix(1, 0, 0, 1)};
        tree = vector<struct node> (SIZE*2 - 1, nullNode);
        buildTree(0, 0, SIZE - 1);
    }
    // MUL (arr[l], ..., arr[r])
    matrix query(int l, int r) {
        return query(0, 0, SIZE - 1, l, r).v;
    }
    // Print the Segment Tree
    void print() {
        for(auto x: tree) {
            cout << setw(2) << x.v.a << ' ' << setw(2) << x.v.b << "  ";
        }
        cout << '\n';
        for(auto x: tree) {
            cout << setw(2) << x.v.c << ' ' << setw(2) << x.v.d << "  ";
        }
        cout << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b, c, d;
    cin >> r >> n >> m;
    vector<matrix> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        v[i] = matrix(a, b, c, d);
    }
    SegmentTree st(v);
    while(m--) {
        int l, r;
        cin >> l >> r;
        matrix ans = st.query(l-1, r-1);
        cout << ans.a << ' ' << ans.b << '\n' << ans.c << ' ' << ans.d << '\n' << '\n';
    }
    return 0;
}