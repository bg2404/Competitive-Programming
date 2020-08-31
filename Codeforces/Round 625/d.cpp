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

vector<vector<int>> adj, adjr;

vector<int> dist;
void bfs(int s = 0){
    vector<bool> visited (adjr.size(),false);
    dist = vector<int> (adjr.size(), INT_MIN);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto &i: adjr[u]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dist[i] = dist[u] + 1;
            }
        }
    }
}

int main(){
    FAST;
    int n, m;
    cin >> n >> m;
    adj = adjr = V<V<int> > (n, V<int>());
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        adjr[v].pb(u);
    }
    int p;
    cin >> p;
    V<int> path(p);
    loop(i, 0, p) {
        cin >> path[i];
        --path[i];
    }
    bfs(path[p-1]);
    // cout << path << '\n';
    // cout << dist << '\n';
    int ma = 0, mi = 0;
    for(int i = 1; i < p; ++i) {
        if(dist[path[i]] + 1 == dist[path[i-1]]) {
            int cnt = 0;
            for(auto u: adj[path[i-1]]) {
                if(dist[u] +1 == dist[path[i-1]]) {
                    ++cnt;
                }
            }
            if(cnt > 1) {
                ++ma;
            }
        } else {
            ++ma;++mi;
        }
    }
    cout << mi << ' ' << ma << '\n';
    return 0;
}