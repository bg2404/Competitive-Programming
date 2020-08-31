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
// #define int int64_t
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

long long power(long long x, unsigned long long y, long long p = MOD2) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) {
            res = (res*x) % p;
        }
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

// C function for extended Euclidean Algorithm 
ll gcdExtended(ll a, ll b, ll *x, ll *y); 
  
// Function to find modulo inverse of b. It returns 
// -1 when inverse doesn't 
ll modInverse(ll b, ll m) 
{ 
    ll x, y; // used in extended GCD algorithm 
    ll g = gcdExtended(b, m, &x, &y); 
  
    // Return -1 if b and m are not co-prime 
    if (g != 1) 
        return -1; 
  
    // m is added to handle negative x 
    return (x%m + m) % m; 
} 
  
// Function to compute a/b under modlo m 
ll modDivide(ll a, ll b, ll m) 
{ 
    a = a % m; 
    ll inv = modInverse(b, m);
    return (inv * a) % m; 
} 
  
// C function for extended Euclidean Algorithm (used to 
// find modular inverse. 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

signed main(){
    FAST;
    long long n, m, l, r;
    cin >> n >> m >> l >> r;
    ll nm;
    nm = n*m;
    if(nm & 1) {
        cout << power(r-l+1, nm) << '\n';
        return 0;
    }
    long long d = r-l, o, e;
    if(d&1) {
        o = e = d/2+1;
    } else {
        o = e = d/2;
        ++e;
    }
    long long ans = ((power(e+o, nm) + power(e-o, nm))%MOD2 * power(2, MOD2-2))%MOD2;
    cout << ans << '\n';
    

    return 0;
}