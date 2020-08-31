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
    ll a, b, c;
    cin >> a >> b >> c;
    ll maxn = 20001;
    V<V<ll> > dp(3, V<ll> (maxn, INT_MAX));
    loop(i, 1, maxn) {
        dp[0][i] = abs(c - i);
    }
    // cout << dp[0] << '\n';
    loop(i, 1, maxn) {
        for(int j = i; j < maxn; j += i) {
            dp[1][i] = min(dp[1][i], abs(b-i) + dp[0][j]);
        }
    }
    // cout << dp[1] << '\n';
    loop(i, 1, maxn) {
        for(int j = i; j < maxn; j += i) {
            dp[2][i] = min(dp[2][i], abs(a-i) + dp[1][j]);
        }
    }
    // cout << dp[2] << '\n';
    a = b = c = INT_MAX;
    ll co = INT_MAX, ans = INT_MAX;
    loop(i, 0 , maxn) {
        // cout << mp(mp(co, dp[2][i]), mp(a,i)) << '\n';
        if(co > dp[2][i]) {
            a = i;
            co = dp[2][i];
        }
    }
    ans = co;
    co = INT_MAX;
    for(int i = a; i < maxn; i += a) {
        if(co > dp[1][i]) {
            b = i;
            co = dp[1][i];
        }
    }
    co = INT_MAX;
    for(int i = b; i < maxn; i += b) {
        if(co > dp[0][i]) {
            c = i;
            co = dp[0][i];
        }
    }
    cout << ans << '\n' << a << ' ' << b << ' ' << c << '\n';
}

int main(){
    FAST;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}