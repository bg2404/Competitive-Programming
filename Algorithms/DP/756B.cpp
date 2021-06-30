// https://codeforces.com/problemset/problem/756/B
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
#define time first
#define cost second
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

int binary_search(vector<PII>& v, int t) {
    int l = 0, r = v.size()-1, m;
    while(l < r) {
        m = l + (r-l)/2;
        if(v[m].time >= t) {
            r = m;
        } else {
            l = m+1;
        }
    }
    if(v[l].time >= t) {
        --l;
    }
    return l;
}

void solve(){
    int n;
    cin >> n;
    V<int> t(n);
    V<PII> mcost;
    for(int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    mcost.pb(mp(t[0], 20));
    cout << mcost[0].cost << '\n';
    int t1, t2, t3;
    loop(i, 1, n) {
        t1 = mcost[i-1].cost + 20;
        t2 = binary_search(mcost, t[i] - 89);
        t3 = binary_search(mcost, t[i] - 1439);
        if(t2 < 0) {
            t2 = 50;
        } else {
            t2 = mcost[t2].cost + 50;
        }
        if(t3 < 0) {
            t3 = 120;
        } else {
            t3 = mcost[t3].cost + 120;
        }
        t1 = min(t1, min(t2, t3));
        mcost.pb(mp(t[i], t1));
        cout << t1 - mcost[i-1].cost << '\n';
    }
}

int main(){
    FAST;
    #ifndef ONLINE_JUDGE
        // FILE_READ_IN;
    #endif
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}