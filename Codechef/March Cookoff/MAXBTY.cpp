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

    return v;
}

int main(){

    FAST;

    test {
        int n, q;
        cin >> n >> q;
        V<ll> b(n), pre_sum(n,0), suf_sum(n,0), maxl(n,0), maxr(n,0);
        
        loop(i, 0, n) {
            cin >> b[i];
        }
        pre_sum[0] = b[0];
        suf_sum[n-1] = b[n-1];
        loop(i, 1, n) {
            pre_sum[i] = pre_sum[i-1] + b[i];
            suf_sum[n-i-1] = suf_sum[n-i] + b[n-i-1];
        }
        ll cmax = INT_MIN;
        maxr[n-1] = 0;
        loopr(i, n-2, 0) {
            cmax = max(cmax, pre_sum[i+1]);
            int y = cmax - pre_sum[i];
            maxr[i] = max(y,0);
        }
        cmax = INT_MIN;
        maxl[0] = 0;
        loop(i, 1, n) {
            cmax = max(cmax, suf_sum[i-1]);
            int y = cmax - suf_sum[i];
            maxl[i] = max(y,0);
        }
        SegmentTree<ll> seg(b, query);
        
        while(q--) {
            char c;
            int x, y;
            cin >> c >> x >> y;
            if(c == 'Q') {
                cout << maxl[x] + maxr[y] + seg.queryRange(x, y) << '\n';
            } else {
                
            }
        }
    }

   return 0;
}