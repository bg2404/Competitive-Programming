#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int> > queries;
vector<int> answer;

template<typename T>
struct node {
    /*
        v = velue at node
    */
    T v;
    int l;
    int r;
};


template<typename T>
class SegmentTree {
    private:
        int MAX;
        vector<struct node<T>*> tree;
        vector<T> v;
        T (*query)(struct node<T>*, struct node<T>*);
        void constructSegmentTree(int root, int l, int r);
        void update(int root, int index, T v);
        struct node<T>* queryRange(int root, int l, int r);
    public:
        SegmentTree(vector<T> v, T (*query)(struct node<T>* a, struct node<T>* b));
        void update(int index, T v);
        T queryRange(int l, int r);
};

template<typename T>
SegmentTree<T>::SegmentTree(vector<T> v, T (*query)(struct node<T>* a, struct node<T>* b)) {
    this->query = query;
    this->v = v;
    MAX = (int)pow(2, 1 + ceil(log2(v.size())));
    tree.resize(MAX);
    constructSegmentTree(0, 0, v.size()-1);
}

template<typename T>
void SegmentTree<T>::constructSegmentTree(int root, int l, int r) {
    if(l == r) {
        tree[root] = new struct node<T>;
        tree[root]->v = v[l];
        tree[root]->l = l;
        tree[root]->r = r;
        return;
    }

    constructSegmentTree(root*2+1, l, l + (r-l)/2);
    constructSegmentTree(root*2+2, l+(r-l)/2 + 1, r);


    tree[root] = new struct node<T>;
    tree[root]->v = query(tree[root*2+1], tree[root*2+2]);
    tree[root]->l = l;
    tree[root]->r = r;
}

template<typename T>
void SegmentTree<T>::update(int index, T v) {
    update(0, index, v);
}

template<typename T>
void SegmentTree<T>::update(int root, int index, T v) {
    if(tree[root]->l == tree[root]->r) {
        tree[root]->v = v;
        return;
    }

    if(tree[root*2+1]->r >= index) {
        update(root*2+1, index, v);
    } else {
        update(root*2+2, index, v);
    }

    tree[root]->v = query(tree[root*2+1], tree[root*2+2]);
}

template<typename T>
T SegmentTree<T>::queryRange(int l, int r) {
    return queryRange(0, l, r)->v;
}

template<typename T>
struct node<T>* SegmentTree<T>::queryRange(int root, int l, int r) {
    if(tree[root]->l == l && tree[root]->r == r) {
        return tree[root];
    }

    if(tree[root*2+2]->l <= l) {
        return queryRange(root*2+2, l, r);
    } else {
        if(tree[root*2+1]->r >= r) {
            return queryRange(root*2+1, l, r);
        } else {
            struct node<T>* tempNode = new struct node<T>;
            tempNode->l = l;
            tempNode->r = r;
            tempNode->v = query(queryRange(root*2+1, l, tree[root*2+1]->r), queryRange(root*2+2, tree[root*2+2]->l, r));
            return tempNode;
        }
    }
}

// some associative and commutative query function
template<typename T>
T query(struct node<T>* a, struct node<T>* b) {
    T v;
    // // Sum Query
    // v = a->v + b->v;

    // // Min Query
    // v = min(a->v, b->v);

    // Max Query
    v = max(a->v, b->v);

    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<int> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    int l0, r0, q;
    cin >> l0 >> r0;

    queries.resize(Q);
    answer.resize(Q);
    for(int i = 0; i < Q; ++i) {
        cin >> q;
        queries[i] = {q, i};
    }
    sort(queries.begin(), queries.end());

    SegmentTree<int> st(A, query);
    
    int k = 0;

    long long ans, l = l0, r = r0;
    for(int i = 0; k < Q; ++i) {
        ans = st.queryRange(l-1, r-1);
        while(i == queries[k].first) {
            answer[queries[k++].second] = ans;
        }
        l = 1 + (l*a + ans*c + e) % N;
        r = 1 + (r*b + ans*d + f) % N;
        if(l > r) {
            swap(l, r);
        }
    }

    for(int i = 0; i < Q; ++i) {
        cout << answer[i] << endl;
    }
    
    return 0;
}