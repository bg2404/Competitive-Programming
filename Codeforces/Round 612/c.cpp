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

int main(){
    FAST;
    // FILE_READ_OUT
    int n, o, e;
    cin >> n;
    o = (n+1)/2;
    e = n/2;
    V<int> p(n);
    set<int> st;
    loop(i, 0, n) {
        cin >> p[i];
        if(p[i] & 1) {
            p[i] = 1;
            --o;
        } else if(p[i]) {
            p[i] = 2;
            --e;
        }
    }

    V<V<V<V<int> > > > dp(n, V<V<V<int> > >(o+1, V<V<int> >(e+1, V<int>(2, inf))));
    if(p[0] == 0) {
        if(o) {
            dp[0][1][0][1] = 0;
        }
        if(e) {
            dp[0][0][1][0] = 0;
        }
    } else {
        if(p[0] == 1) {
            dp[0][0][0][1] = 0;
        } else {
            dp[0][0][0][0] = 0;
        }
    }
    loop(i, 1, n) {
        loop(j, 0, o+1) {
            loop(k, 0, e+1) {
                if(p[i] == 1) {
                    dp[i][j][k][1] = min(dp[i-1][j][k][1], dp[i-1][j][k][0] + 1);
                } else if(p[i] == 2) {
                    dp[i][j][k][0] = min(dp[i-1][j][k][0], dp[i-1][j][k][1] + 1);
                } else {
                    if(k) dp[i][j][k][0] = min(dp[i-1][j][k-1][0], dp[i-1][j][k-1][1] + 1);
                    if(j) dp[i][j][k][1] = min(dp[i-1][j-1][k][1], dp[i-1][j-1][k][0] + 1);
                }
            }
        }
    }

    int ans =  min(dp[n-1][o][e][0], dp[n-1][o][e][1]);
    cout << ans << '\n';
    
    // for(auto a: dp) {
    //     for(auto b: dp) {
    //         cout << b << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}