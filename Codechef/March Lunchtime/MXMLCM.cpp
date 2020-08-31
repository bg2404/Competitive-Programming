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

V<int> primes;

void sieve(int n=10000) {
    V<bool> prime(n+1,true);
    prime[0] = prime[1] = false;
    for(int p = 2; p*p <= n; ++p) {
        if(prime[p]) {
            for(int i = p*p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    loop(i, 0, prime.size()) {
        if(prime[i]) {
            primes.pb(i);
        }
    }
}

ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
  
// Returns LCM of array elements 
ll findlcm(V<ll> arr, int n) 
{ 
    // Initialize result 
    ll ans = arr[0]; 
  
    // ans contains LCM of arr[0], ..arr[i] 
    // after i'th iteration, 
    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
}
void solve(){
    int n,m;
    cin >> n >> m;
    map<int, int> used;
    V<ll> a(n);
    loop(i,0,n) {
        cin >> a[i];
        // for(int j = 0; primes[j] <= a[i] && j < primes.size(); ++j) {
        //     int t = a[i], c = 0;
        //     while(t%primes[j] == 0) {
        //         t /= primes[i];
        //         ++c;
        //     }
        //     used[primes[j]] = max(c, used[primes[j]]);
        // }
    }
    ll lcm = findlcm(a, n);
    int t = 1;
    loop(i, 1, m+1) {
        ll x = findlcm({lcm, i}, 2);
        if(x > lcm) {
            lcm = x;
            t = i;
        }
    }
    cout << t << '\n';
    
}

int main(){
    FAST;
    sieve();
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