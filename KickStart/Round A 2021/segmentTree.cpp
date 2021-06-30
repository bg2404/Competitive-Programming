#include <bits/stdc++.h>

using namespace std;

template <typename T>
class SegmentTree {
    T default;
    vector<T> tree;
    int SIZE;

    T operation(T a, T b) {  // Set krna h isko
        return a + b;
    }

    void constructSegmentTree(vector<T> &v, int l, int r, int root) {
        if (l == r) {
            if (r < v.size()) {
                tree[root] = v[r];
            }
        } else {
            int m = (l + r) >> 1;
            constructSegmentTree(v, l, m, root * 2 + 1);
            constructSegmentTree(v, m + 1, r, root * 2 + 2);
            tree[root] = operation(tree[root * 2 + 1], tree[root * 2 + 2]);
        }
    }

    void update(int root, int l, int r, int idx, int v) {
        if (l == r) {
            if (r == idx) {
                tree[root] = v;
            }
        } else {
            int m = (l + r) >> 1;
            if (idx > m) {
                update(root * 2 + 2, m + 1, r, idx, v);
            } else {
                update(root * 2 + 1, l, m, idx, v);
            }
        }
    }

   public:
    SegmentTree(vector<T> &v) {
        MAXSIZE = 1;
        int size = SIZE;
        while (SIZE < size) {
            SIZE <<= 1;
        }
        tree.resize(2 * SIZE - 1);
        default = 0;  // Set krna h isko
        constrcutSegmentTree(v, 0, SIZE - 1, 0);
    }

    void update(int idx, int v) {
        ;
    }
};