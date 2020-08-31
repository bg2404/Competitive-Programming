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

int n;
vector<vector<int>> adj;
vector<int>leaves;


void removeNode(int s) {
    loop(i, 1, n+1) {
        adj[i].erase(std::remove(adj[i].begin(), adj[i].end(), s), adj[i].end());
    }
    adj[s].clear();
}

void getLeaves() {
    leaves.clear();
    loop(i, 1, n+1) {
        if(adj[i].size() == 1) {
            leaves.pb(i);
        }
    }
}

int main(){
    FAST;
    cin >> n;
    adj = V<V<int> >(n+1, V<int>());
    int u, v;
    loop(i, 1, n) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    set<int> pos;
    loop(i, 1, n+1) {
        pos.insert(i);
    }
    int root = 0;
    getLeaves();
    while(leaves.size() > 1) {
        int u = leaves[0], v = leaves[1];
        cout << "? " << u << " " << v << endl;
        int anc;
        cin >> anc;
        if(anc == u || anc == v) {
            root = anc;
            break;
        }
        if(anc == -1) {
            return 0;
        }
        removeNode(u);
        removeNode(v);
        pos.erase(u);
        pos.erase(v);
        getLeaves();
    }
    // cout << leaves << '\n';
    // cout << adj << '\n';
    if(root == 0) {
        root = *pos.begin();
    }
    cout << "! " << root << endl;
    return 0;
}