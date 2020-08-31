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

int n, m, k;
V<int> a, b;
map<int, bool> fm;

void divide(int n) {
    for(int i = 1; i*i <= n; ++i) {
        if(n % i == 0) {
            fm[i] = 1;
            fm[n/i] = 1;
        } 
    }
}

int main(){
    FAST;
    cin >> n >> m >> k;
    divide(k);
    a = V<int>(n);
    b = V<int>(m);
    loop(i, 0, n) {
        cin >> a[i];
    }
    loop(i, 0, m) {
        cin >> b[i];
    }

    V<int> fa, fb;
    int i = 0;
    while(!a[i] && i < n) {
        ++i;
    }
    int c = -1;
    for(; i < n; ++i) {
        if(a[i] && c == -1) {
            c = i;
        }
        if(!a[i] && c > -1) {
            int f = i - c;
            fa.pb(f);
            c = -1;
        }
    }

    if(c > -1) {
        int f = n-c;
        fa.pb(f);
    }

    i = 0;
    while(!b[i] && i < m) {
        ++i;
    }
    c = -1;
    for(; i < m; ++i) {
        if(b[i] && c == -1) {
            c = i;
        }
        if(!b[i] && c > -1) {
            int f = i - c;
            fb.pb(f);
            c = -1;
        }
    }

    if(c > -1) {
        int f = m-c;
        fb.pb(f);
    }

    sort(all(fa));
    sort(all(fb));

    // cout << fa << '\n' << fb << '\n' << fm << '\n';
    if(fa.size() == 0 || fb.size() == 0) {
        cout << 0 << '\n';
        return 0;
    }

    V<PII> dp;
    for(auto [f, m]: fm) {
        if(m) {
            dp.pb(mp(f, 0));
        }
    }
    sort(all(dp));
    
    loop(i, 0, dp.size()) {
        int d = k / dp[i].F;
        auto idx = lower_bound(all(fb), d) - fb.begin();
        // cout << idx <<  '\n';
        if(idx < n) {
            if(fb[idx] >= d) {
                loop(j, idx, (int)fb.size()) {
                    dp[i].S += fb[j]-d+1;
                }
            }
        }
    }
    cout << dp << '\n';

    ll ans = 0;

    loop(i, 0, (int)fa.size()) {
        int idx = lower_bound(all(dp), mp(fa[i]+1, 0)) - dp.begin();
        loop(j, 0, idx) {
            ans += (dp[j].S*1LL)*(fa[i] - dp[j].F + 1);
        }
    }

    cout << ans << '\n';

    return 0;
}