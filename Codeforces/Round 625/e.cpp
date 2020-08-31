
#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define MOD2 998244353
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;++i)
#define loopr(i,a,b) for(int i=a;i>=b;--i)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;

template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

template<typename T>
struct node {
    /*
        v = velue at node
    */
    T v;
};


template<typename T>
class SegmentTree {
    private:
        int MAX;
        vector<struct node<T>> tree;
        struct node<T> nullNode;
        vector<T> arr;
        T (*query)(struct node<T>, struct node<T>);
        void constructSegmentTree(int root, int l, int r);
        void update(int root, int x, int y, int index, T v);
        struct node<T> queryRange(int root, int x, int y, int l, int r);
    public:
        SegmentTree(vector<T> v, T (*query)(struct node<T> a, struct node<T> b));
        void update(int index, T v);
        T queryRange(int l, int r);
};

template<typename T>
SegmentTree<T>::SegmentTree(vector<T> v, T (*query)(struct node<T> a, struct node<T> b)) {
    this->query = query;
    this->arr = v;
    MAX = (int)pow(2, 1 + ceil(log2(v.size())));
    tree.resize(MAX);
    constructSegmentTree(0, 0, v.size()-1);
}

template<typename T>
void SegmentTree<T>::constructSegmentTree(int root, int l, int r) {
    if(l == r) {
        tree[root].v = arr[l];
        return;
    }

    constructSegmentTree(root*2+1, l, l + (r-l)/2);
    constructSegmentTree(root*2+2, l+(r-l)/2 + 1, r);

    tree[root].v = query(tree[root*2+1], tree[root*2+2]);
}

template<typename T>
void SegmentTree<T>::update(int index, T v) {
    update(0, 0, arr.size()-1, index, v);
}

template<typename T>
void SegmentTree<T>::update(int root, int x, int y, int index, T v) {
    if(x > y) {
        return;
    }
    if(x == y) {
        if(x == index) {
            tree[root].v = v;
        }
        return;
    }

    int mid = x + (y-x)/2;

    if(mid >= index) {
        update(root*2+1, x, mid, index, v);
    } else {
        update(root*2+2, mid+1, y, index, v);
    }

    tree[root].v = query(tree[root*2+1], tree[root*2+2]);
}

template<typename T>
T SegmentTree<T>::queryRange(int l, int r) {
    return queryRange(0, 0, arr.size()-1, l, r).v;
}

template<typename T>
struct node<T> SegmentTree<T>::queryRange(int root, int x, int y, int l, int r) {
    if(x > r || y < l) {
        return nullNode;
    }

    if(x >= l && y <= r) {
        return tree[root];
    }

    int mid = x + (y-x) / 2;

    struct node<T> left = queryRange(root*2+1, x, mid, l, r), right = queryRange(root*2+2, mid+1, y, l, r), tempNode;
    tempNode.v = query(left, right);
    return tempNode;
}

// some associative and commutative query function
template<typename T>
T query(struct node<T> a, struct node<T> b) {
    T v;
    // Sum Query
    v = a.v + b.v;

    // Min Query
    v = min(a.v, b.v);

    // Max Query
    v = max(a.v, b.v);

    return v;
}

int main(){
    FAST;
    int n, m, p;
    cin >> n >> m >> p;
    V<int> temp(m);
    V<PII> a(n), b(m);
    V<P<PII, int> > c(p);
    loop(i, 0, n) {
        cin >> a[i].F >> a[i].S;
    }

    loop(i, 0, m) {
        cin >> b[i].F >> b[i].S;
        temp[m]=-b[i].S;
    }
    loop(i, 0, p) {
        cin >> c[i].F.F >> c[i].F.S >> c[i].S;
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));

    SegmentTree<int> st(temp, query);
    
    
    return 0;
}