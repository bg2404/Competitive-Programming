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
V<ll> dp;
V<ll> sz;
int dfs(int s = 0){
// void dfs(int s = 0) {
    visited[s] = true;
    int count = 1;
    for(auto &i: adj[s]) {
        if(!visited[i]) {
            count += dfs(i);
            dp[s] += dp[i];
            // dfs(i);
        }
    }
    dp[s] += count;
    return sz[s] = count;
    return count;
}

// void dfs(int s = 0){
//     visited[s] = true;
//     for(auto &i: adj[s]) {
//         if(!visited[i]) dfs(i);
//     }
// }
ll ans = 0;
void solveDP(int s = 0) {
    ans = max(ans, dp[s]);
    visited[s] = true;
    // cout << s << ' ' << dp << '\n';
    for(auto &i: adj[s]) {
        if(!visited[i]) {
            ll tdps = dp[s];
            ll tdpi = dp[i];
            ll tszs = sz[s];
            ll tszi = sz[i];
            sz[s] = sz[s] - sz[i];
            dp[s] = dp[s] - dp[i] - sz[i];
            dp[i] = dp[i] + dp[s] + sz[s];
            sz[i] = sz[i] + sz[s];
            solveDP(i);
            sz[s] = tszs;
            dp[s] = tdps;
            dp[i] = tdpi;
            sz[i] = tszi;
        }
    }
}

int main(){
    FAST;
    int n;
    cin >> n;
    adj = V<V<int> >(n, V<int>());
    visited = V<bool>(n, false);
    dp = sz = V<ll>(n, 0);
    loop(i, 1, n) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // cout << adj << '\n' << visited << '\n';
    dfs(0);
    visited = V<bool>(n, false);
    solveDP(0);
    ll m = dp[0];
    loop(i, 1, n) {
        m = max(m, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}