#include<bits/stdc++.h>

using namespace std;

class SegmentTree {
    vector<int> arr;
    int MAX_SIZE;
    int size;
    int single(int x) {
        return x;
    }
    int merge(int a, int b) {
        return a + b;
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
    void update(int root, int x, int y, int idx, int v) {
        if(x < y) {
            if(y - x == 1) {
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
    SegmentTree(int n) { // Initialize with a n-length zer filled array
        MAX_SIZE = 1;
        size = n;
        while(MAX_SIZE < size) {
            MAX_SIZE <<= 1;
        }
        arr.assign(MAX_SIZE << 1, 0);
    }
    SegmentTree(vector<int> &a) : SegmentTree(a.size()) {
        buildSegmentTree(a, 0, 0, MAX_SIZE);
    }
    void update(int idx, int v) {
        update(0, 0, MAX_SIZE, idx, v);
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
        st.update(i, i+1);
        st.print();
    }
    return 0;
}