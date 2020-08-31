#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define MOD2 998244353
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;++i)
#define loope(i,a,b) for(int i=a;i<=b;++i)
#define loopr(i,a,b) for(int i=a;i>=b;--i)
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

int main(){
    FAST;
    int n, m;
    cin >> n >> m;
    V<int> p(n), v(n), num(n);
    loop(i, 0, n) {
        cin >> p[i];
    }
    loop(i, 0, n) {
        cin >> v[i];
    }
    int sum = 0;
    loop(i, 0, n) {
        cin >> num[i];
        sum += num[i];
    }
    V<int> wei(sum), val(sum);
    int k = 0;
    loop(i, 0, n) {
        loop(j, 0, num[i]) {
            wei[k] = p[i];
            val[k++] = v[i];
        }
    }
    // cout << val << ' ';
    n = sum;
    V<V<int> > dp(n+1, V<int>(m+1, 0));

    loope(i, 1, n) {
        loope(j, 1, m) {
            if(wei[i-1] <= j) {
                dp[i][j] = max(val[i-1] + dp[i-1][j - wei[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}