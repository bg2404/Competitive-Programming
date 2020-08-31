// Attempt 1 - Successful (Without Copy and Paste)

#include <bits/stdc++.h>

using namespace std;


// Update node, nullNode, query and single element initialization
class SegmentTree {
    private:
        int MAX;
        vector<int> tree;
        int nullNode;
        vector<int> arr;
        int query(int a, int b);
        void constructSegmentTree(int root, int l, int r);
        void update(int root, int x, int y, int index);
        int query(int root, int x, int y, int k);
    public:
        SegmentTree(vector<int> v);
        void update(int index);
        int query(int k);
        void print() {
            for(auto x: tree) {
                cout << x << ' ';
            }
            cout << endl;
        }
};

SegmentTree::SegmentTree(vector<int> v) {
    this->arr = v;
    MAX = (int)pow(2, 1 + (int)log2(v.size()));
    nullNode = 0;
    tree = vector<int> (2*MAX-1, 0);
    constructSegmentTree(0, 0, MAX - 1);
}

void SegmentTree::constructSegmentTree(int root, int l, int r) {
    if(l > r) {
        return;
    }
    if(l == r) {
        if(l < arr.size()) {
            tree[root] = arr[l];
        }
        return;
    }

    constructSegmentTree(root*2+1, l, l + (r-l)/2);
    constructSegmentTree(root*2+2, l+(r-l)/2 + 1, r);

    tree[root] = query(tree[root*2+1], tree[root*2+2]);
}

void SegmentTree::update(int index) {
    update(0, 0, MAX-1, index);
}

void SegmentTree::update(int root, int x, int y, int index) {
    if(x > y) {
        return;
    }
    if(x == y) {
        if(x == index) {
            tree[root] ^= 1;
        }
        return;
    }

    int mid = x + (y-x)/2;

    if(mid >= index) {
        update(root*2+1, x, mid, index);
    } else {
        update(root*2+2, mid+1, y, index);
    }

    tree[root] = query(tree[root*2+1], tree[root*2+2]);
}

int SegmentTree::query(int k) {
    return query(0, 0, MAX-1, k);
}

int SegmentTree::query(int root, int x, int y, int k) {
    if(x > y || tree[root] < k || k < 1) {
        return -1;
    }

    if(x == y) {
        if(tree[root] == k) {
            return x;
        } else {
            return -1;
        }
    }

    int mid = x + (y-x) / 2;

    int left = query(root*2+1, x, mid, k);
    if(left == -1) {
        return query(root*2 + 2, mid + 1, y, k - tree[root*2+1]);
    } else {
        return left;
    }
}

// some associative query function
int SegmentTree::query(int a, int b) {
    return a+b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x, v;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    SegmentTree st(a);
    // st.print();
    for(int i = 0; i < m; ++i) {
        cin >> x >> v;
        if(x == 1) {
            st.update(v);
        } else {
            cout << st.query(v+1) << '\n';
        }
        // st.print();
    }

    return 0;
}