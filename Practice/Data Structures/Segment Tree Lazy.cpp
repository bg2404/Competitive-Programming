#include<bits/stdc++.h>

using namespace std;

// Interval Update arr[l, r) -> v
// Interval Query arr[l, r) -> arr[l] + --- + arr[r-1]
class SegmentTree {
    vector<int> arr;
    vector<int> lazy;
    int MAX_SIZE;
    int size;
    int nullValue;
    int single(int x) {
        return x;
    }
    int merge(int a, int b) {
        return a + b;
    }
    void lazyUpdate(int root, int x, int y) {
        if(x < y && lazy[root] != nullValue) {
            if(y - x > 1) {
                lazy[root*2+1] = lazy[root];
                lazy[root*2+2] = lazt[root];
            }
            arr[root] = (y-x) * lazy[root];
            lazy[root] = nullValue;
        }
    }
    void buildSegmentTree(vector<int> &a, int root, int x, int y) {
        if(x < y) {
            if(y - x == 1) {
                if(x < size) {
                    arr[root] = single(a[x]);
                }
            } else {
                int m = (x + y) / 2;
                buildSegmentTree(a, root * 2 + 1, x, m);
                buildSegmentTree(a, root * 2 + 2, m, y);
                arr[root] = merge(arr[root*2+1], arr[root*2+2]);
            }
        }
    }
    void update(int root, int x, int y, int l, int r, int v) {
        if(x < y) {
            lazyUpdate(root, x, y);
            if(r <= x || y <= l) {
                ;
            } else if(x >= l && r >= y) {
                if(x == idx) {
                    arr[root] = single(v);
                }
            } else if(x <= idx && y > idx) {
                int m = (x + y) / 2;
                if(idx < m) {
                    update(root * 2 + 1, x, m, idx, v);
                } else {
                    update(root * 2 + 2, m, y, idx, v);
                }
                arr[root] = merge(arr[root*2+1], arr[root*2+2]);
            }
        }
    }
    int query(int root, int x, int y, int l, int r) {
        if(x < y) {
            lazyUpdate(root, x, y);
            if(y <= l || r <= x || x >= y) {
                return 0;
            } else if(y > l && x < r) {
                return arr[root];
            } else {
                int m = (x + y) / 2;
                return merge(query(root*2+1, x, m, l, r), query(root*2+2, m, y, l, r));
            }
        }
    }
public:
    SegmentTree(int n) {
        MAX_SIZE = 1;
        size = n;
        nallValue = 0;
        while(MAX_SIZE < size) {
            MAX_SIZE <<= 1;
        }
        arr.assign(MAX_SIZE << 1, 0);
        lazy.assign(MAX_SIZE << 1, 0);
    }
    SegmentTree(vector<int> &a) : SegmentTree(a.size()) {
        buildSegmentTree(a, 0, 0, MAX_SIZE);
    }
    void update(int l, int r, int v) {
        update(0, 0, MAX_SIZE, l, r, v);
    }
    int query(int l, int r) {
        return query(0, 0, MAX_SIZE, l, r);
    }
    void print() {
        for(int i: arr) {
            cout << i << ' ';
        }
        cout << '\n';
    }
};

int main() {
    vector<int> a({8, 7, 6, 5, 4, 3, 2, 1});
    SegmentTree st(a);
    st.print();
    for(int i = 0; i < 8; ++i) {
        int q, l, r;
        cin >> q >> l >> r;
        if(q == 1) {
            int v;
            cin >> v;
            st.update();
        }
    }
    return 0;
}