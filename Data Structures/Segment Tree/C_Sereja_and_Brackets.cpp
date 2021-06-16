// Attempt 1 - Successful (Without Copy and Paste)

#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>

using namespace std;

struct node {
    int v;
    int o;
    int c;
}nullNode;


class SegmentTree {
    private:
        int MAX;
        vector<struct node> tree;
        string s;
        int (*query)(int, int);
        void constructSegmentTree(int root, int l, int r);
        struct node queryRange(int root, int x, int y, int l, int r);
    public:
        SegmentTree(string s, int (*query)(int a, int b));
        int queryRange(int l, int r);
};

SegmentTree::SegmentTree(string s, int (*query)(int a, int b)) {
    MAX = (int)pow(2, 1 + ceil(log2(s.size())));
    tree.resize(MAX);
    this->query = query;
    this->s = s;
    constructSegmentTree(0, 0, s.size()-1);
}

void SegmentTree::constructSegmentTree(int root, int l, int r) {
    if(l == r) {
        tree[root].v = 0;

        if(s[l] == '(') {
        tree[root].c = 0;
            tree[root].o = 1;
        } else {
        tree[root].o = 0;
                tree[root].c = 1;
        }

        return;
    }

    constructSegmentTree(root*2+1, l, l + (r-l)/2);
    constructSegmentTree(root*2+2, l+(r-l)/2 + 1, r);
    
    int temp = min(tree[2*root+1].o, tree[2*root+2].c);

    tree[root].v = tree[2*root+1].v + tree[2*root+2].v + 2*temp;
    tree[root].o = tree[2*root+1].o + tree[2*root+2].o - temp;
    tree[root].c = tree[2*root+1].c + tree[2*root+2].c - temp;
}

int SegmentTree::queryRange(int l, int r) {
    return queryRange(0, 0, s.size()-1, l, r).v;
}

struct node SegmentTree::queryRange(int root, int x, int y, int l, int r) {
    if(x > r || y < l) {
        return nullNode;
    }

    if(x >= l && y <= r) {
        return tree[root];
    }

    int mid = x + (y-x)/2;
    struct node left = queryRange(2*root+1, x, mid, l, r), right = queryRange(2*root+2, mid + 1, y, l, r), tempNode;
    int temp = min(left.o, right.c);
    tempNode.v = left.v + right.v + 2*temp;
    tempNode.o = left.o + right.o - temp;
    tempNode.c = left.c + right.c - temp;

    return tempNode;
}

int query(int a, int b) {
    // some associative and commutative query function
    return a + b;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    string s;
    cin >> s;

    SegmentTree st(s, query);

    nullNode.v = 0;
    nullNode.o = 0;
    nullNode.c = 0;
    
    int m;
    cin >> m;

    int l, r;
    for(int i = 0; i < m; ++i) {
        cin >> l >> r;
        cout << st.queryRange(l-1, r-1) << '\n';
    }
    
    return 0;
}