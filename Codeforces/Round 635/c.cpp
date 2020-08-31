#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define MOD2 998244353
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

vector<vector<int>> adj;
vector<bool> visited;
map<int, V<int>> depth;
V<int> deep;
V<int> par;
V<int> type;
V<int> sz;
int dfs(int s = 0, int d = 0, int p = -1){
    visited[s] = true;
    depth[d].pb(s);
    deep[s] = d;
    par[s] = p;
    int h = 0;
    for(auto &i: adj[s]) {
        if(!visited[i]) {
            h += dfs(i, d+1, s);
        }
    }
    sz[s] = h;
    return h+1;
}

int comp(int a, int b) {
    return deep[a] - sz[a] > deep[b] - sz[b];
}
int main(){
    FAST;
    int n, k;
    cin >> n >> k;
    adj = V<V<int> > (n, V<int>());
    par = type = deep = sz = V<int>(n, 0);
    visited = V<bool>(n, false);
    loop(i, 1, n) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    V<int> city(n);
    loop(i, 0, n) {
        city[i] = i;
    }
    sort(all(city), comp);
    // V<PII> ds;
    // int ans = 0, count = 0;
    // for(auto itr = depth.rbegin(); itr != depth.rend(); ++itr) {
    //     sort(all(itr->S), comp);
    //     ds.pb(mp(itr->F,itr->S.size()));
    // }
    ll count = 0, ans = 0;
    // cout << '[';
    for(int i = 0; i < k; ++i) {
        // cout << city[i];
        ans += deep[city[i]] - sz[city[i]];
        // cout << mp(deep[city[i]], sz[city[i]]) << ", ";
    }
    // cout << "] ";
    cout << ans << '\n';
    return 0;
}