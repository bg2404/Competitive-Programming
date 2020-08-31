#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define MOD2 998244353
#define test ll t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define loopr(i,a,b) for(ll i=a;i>=b;i--)
#define loops(i,a,b,step) for(ll i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(ll i=a;i>=b;i-=step)
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
    T v;
    ll idx;

    node() {
        v = inf+inf;
        idx = 0;
    }
};


template<typename T>
class SegmentTree {
    private:
        ll MAX;
        vector<struct node<T>> tree;
        struct node<T> nullNode;
        vector<T> arr;
        struct node<T> (*query)(struct node<T>, struct node<T>);
        void constructSegmentTree(ll root, ll l, ll r);
        void update(ll root, ll x, ll y, ll index, T v);
        struct node<T> queryRange(ll root, ll x, ll y, ll l, ll r);
    public:
        SegmentTree(vector<T> v, struct node<T> (*query)(struct node<T> a, struct node<T> b));
        void update(ll index, T v);
        ll queryRange(ll l, ll r);
};

template<typename T>
SegmentTree<T>::SegmentTree(vector<T> v, struct node<T> (*query)(struct node<T> a, struct node<T> b)) {
    this->query = query;
    this->arr = v;
    MAX = (ll)pow(2, 1 + ceil(log2(v.size())));
    tree.resize(MAX);
    constructSegmentTree(0, 0, v.size()-1);
    // loop(i, 0, MAX) {
    //     cout << mp(tree[i].v, tree[i].idx) << ' ';
    // }
    // cout << '\n';
}

template<typename T>
void SegmentTree<T>::constructSegmentTree(ll root, ll l, ll r) {
    if(l == r) {
        tree[root].v = arr[l];
        tree[root].idx = l;
        return;
    }

    constructSegmentTree(root*2+1, l, l + (r-l)/2);
    constructSegmentTree(root*2+2, l+(r-l)/2 + 1, r);

    tree[root] = query(tree[root*2+1], tree[root*2+2]);
}

template<typename T>
ll SegmentTree<T>::queryRange(ll l, ll r) {
    return queryRange(0, 0, arr.size()-1, l, r).idx;
}

template<typename T>
struct node<T> SegmentTree<T>::queryRange(ll root, ll x, ll y, ll l, ll r) {
    if(x > r || y < l) {
        return nullNode;
    }

    if(x >= l && y <= r) {
        return tree[root];
    }

    ll mid = x + (y-x) / 2;

    struct node<T> left = queryRange(root*2+1, x, mid, l, r), right = queryRange(root*2+2, mid+1, y, l, r), tempNode;
    tempNode = query(left, right);
    return tempNode;
}

// some associative and commutative query function
template<typename T>
struct node<T> query(struct node<T> a, struct node<T> b) {
    if(a.v > b.v) {
        return b;
    }
    return a;
}

ll solve(vector<ll> &v, ll l, ll r, SegmentTree<ll> &segTree) {
    if(l > r) {
        return -inf;
    }
    if(l == r) {
        return v[l];
    }
    ll pivot = segTree.queryRange(l, r);
    // cout << mp(mp(l+1,r+1), pivot+1);
    ll count = v[pivot];
    ll temp1 = v[pivot]*(pivot-l) + solve(v, pivot+1, r, segTree);
    ll temp2 = v[pivot]*(r-pivot) + solve(v, l, pivot-1, segTree);
    if(temp1 > temp2) {
        loop(i, l, pivot) {
            v[i] = v[pivot];
        }
        return temp1 + count;
    } else {
        loop(i, pivot + 1, r+1) {
            v[i] = v[pivot];
        }
        return temp2 + count;
    }
    return 0;
}

signed main(){
    FAST;
    ll n;
    cin >> n;
    V<ll> m(n);
    loop(i, 0, n) {
        cin >> m[i];
    }
    SegmentTree<ll> segTree(m, query);

    solve(m, 0, n-1, segTree);
    loop(i, 0, n) {
        cout << m[i] << ' ';
    }
    cout << '\n';

    return 0;
}