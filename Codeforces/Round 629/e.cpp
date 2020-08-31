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

int T = 0;
vector<vector<int>> adj;
vector<int> tin, tout;
vector<int> p, d;
vector<bool> visited;

void dfs(int s = 0, int par = 0, int dep = 0){
    visited[s] = true;
    p[s] = par;
    d[s] = dep;
    tin[s] = T++;
    for(auto &i: adj[s]) {
        if(!visited[i]) dfs(i, s, dep + 1);
    }
    tout[s] = T++;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void solve() {
    int n;
    cin >> n;
    V<int> v(n);
    loop(i, 0, n) {
        cin >> v[i];
        --v[i];
    }
    // cout << v << ' ';
    int deep = v[0];
    for(auto u: v) {
        if(d[u] > d[deep]) {
            deep = u;
        }
    }

    for(auto &u: v) {
        if(u == deep) continue;
        u = p[u];
    }

    // cout << v << ' ';

    for(auto u: v) {
        // cout << mp(u, deep) << ' ';
        if(!isAncestor(u, deep)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    FAST;
    int n, m;
    cin >> n >> m;
    adj = V<V<int> >(n, V<int>());
    tin = tout = p = d = V<int> (n);
    visited = V<bool>(n);
    loop(i, 1, n) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    // cout << p << '\n';
    while(m--) {
        solve();
    }
    return 0;
}