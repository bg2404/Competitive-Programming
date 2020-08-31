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

void solve(){
    int n;
    cin >> n;
    vector<bool> king(n,0);
    vector<bool> queen(n,0);
    vector<vector<int> > g(n, vector<int>());
    for(int i = 0; i < n; ++i) {
        int k, p;
        cin >> k;
        while(k--) {
            cin >> p;
            g[i].push_back(p-1);
        }
        sort(all(g[i]));
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < g[i].size(); ++j) {
            if(!king[g[i][j]]) {
                queen[i] = king[g[i][j]] = 1;
                break;
            }
        }
    }

    V<int> uk, uq;
    for(int i = 0; i < n; ++i) {
        if(!king[i]) {
            uk.push_back(i+1);
        }
        if(!queen[i]) {
            uq.pb(i+1);
        }
    }
    if(uk.size() == 0) {
        cout << "OPTIMAL\n";
        return;
    }
    cout << "IMPROVE\n";
    cout << uq[0] << ' ' << uk[0] << '\n';
}

int main(){
    FAST;
    #ifndef ONLINE_JUDGE
        // FILE_READ_IN;
    #endif
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}