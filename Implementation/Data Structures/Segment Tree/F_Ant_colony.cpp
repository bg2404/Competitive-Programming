#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
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

template<typename T>
struct node {
    T v;
    int c;
};


template<typename T>
class SegmentTree {
    private:
        int MAX;
        vector<struct node<T>> tree;
        struct node<T> nullNode;
        vector<T> arr;
        struct node<T> (*query)(struct node<T>, struct node<T>);
        void constructSegmentTree(int root, int l, int r);
        struct node<T> queryRange(int root, int x, int y, int l, int r);
    public:
        SegmentTree(vector<T> v, struct node<T> (*query)(struct node<T> a, struct node<T> b));
        struct node<T> queryRange(int l, int r);
};

template<typename T>
SegmentTree<T>::SegmentTree(vector<T> v, struct node<T> (*query)(struct node<T> a, struct node<T> b)) {
    this->query = query;
    this->arr = v;
    nullNode.v = 0;
    nullNode.c = 0;
    MAX = (int)pow(2, 1 + ceil(log2(v.size())));
    tree.resize(MAX);
    constructSegmentTree(0, 0, v.size()-1);

    // for(auto u: tree) {
    //     cout << u.v << ' ' << u.c << '\n';
    // }
}

template<typename T>
void SegmentTree<T>::constructSegmentTree(int root, int l, int r) {
    if(l == r) {
        tree[root].v = arr[l];
        tree[root].c = 1;
        return;
    }

    constructSegmentTree(root*2+1, l, l + (r-l)/2);
    constructSegmentTree(root*2+2, l+(r-l)/2 + 1, r);

    tree[root] = query(tree[root*2+1], tree[root*2+2]);
}

template<typename T>
struct node<T> SegmentTree<T>::queryRange(int l, int r) {
    return queryRange(0, 0, arr.size()-1, l, r);
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

    struct node<T> left = queryRange(root*2+1, x, mid, l, r), right = queryRange(root*2+2, mid+1, y, l, r);
    return query(left, right);
}

// some associative and commutative query function
template<typename T>
struct node<T> query(struct node<T> a, struct node<T> b) {
    struct node<T> c;
    c.v = __gcd(a.v, b.v);
    if(b.v == a.v) {
        c.c = a.c + b.c;
    } else if(a.v == c.v) {
        c.c = a.c;
    } else if(b.v == c.v) {
        c.c = b.c;
    } else {
        c.c = 0;
    }

    return c;
}

int n;
V<ll> s;
int main(){
    FAST;
    cin >> n;
    s = V<ll>(n);
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    SegmentTree<ll> st(s, query);
    int m;
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        auto ans = st.queryRange(l, r);
        cout << r - l + 1 - ans.c << '\n';
    }
    return 0;
}