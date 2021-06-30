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

int power(int x, unsigned int y, int p = MOD) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) {
            res = (res*1LL*x) % p;
        }
        y = y>>1;
        x = (x*1LL*x) % p;
    }
    return res;
}

int modInverse(int n, int p) {
    return power(n, p-2, p);
}

int nCrModPFermat(int n, int r, int p) {
    if(r == 0 || n == r) {
        return 1;
    }
    if(r == 1 || r == n-1) {
        return n;
    }

    int factorial[n+1];
    factorial[0] = 1;
    loop(i, 1, n+1) {
        factorial[i] = (factorial[i-1]*1LL*i)%p;
    }

    return (((factorial[n]*1LL*modInverse(factorial[n-r], p)) % p)*1LL*modInverse(factorial[r], p))%p;
}

V<int> dp;

int main(){
    FAST;
    int k;
    cin >> k;
    dp = V<int>(k);
    V<int> c(k);
    loop(i, 0, k) {
        cin >> c[i];
    }
    dp[0] = 1;
    int s = c[0];
    loop(i, 1, k) {
        // cout << s << ' ' << c[i] << '\n';
        dp[i] = (dp[i-1] * 1LL * nCrModPFermat(s+c[i]-1, c[i]-1, MOD)) % MOD;
        s += c[i];
    }
    // cout << dp << '\n';
    cout << dp[k-1] << '\n';
    return 0;
}