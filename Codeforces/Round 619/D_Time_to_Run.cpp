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
#define V vector
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

char R = 'R', L = 'L', U = 'U', D = 'D';

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int maxpos = n*m*4 - 2*n - 2*m;
    if(maxpos < k) {
        cout << "NO\n";
        return;
    }

    cout << "YES" << '\n';
    V<P<int, char> > ans;
    int r = 1;
    while(k && r < n) {
        ++r;
        if(m > 1) {
            if(k) {
                ans.pb( mp( min(k, m-1), R ) );
                k = max(0, k-m+1);
            }
            if(k) {
                ans.pb( mp( min(k, m-1), L ) );
                k = max(0, k-m+1);
            }
        }
        if(k) {
            ans.pb( mp(1, D) );
            --k;
        }
    }
    if(m > 1) {
        if(k) {
            ans.pb( mp( min(k, m-1), R ) );
            k = max(0, k-m+1);
        }
    }
    
    int c = m-1;

    while(k && c > 0) {
        --c;
        if(n > 1) {
            if(k) {
                ans.pb( mp( min(k, n-1), U ) );
                k = max(0, k-n+1);
            }
            if(k) {
                ans.pb( mp( min(k, n-1), D ) );
                k = max(0, k-n+1);
            }
        }
        if(k) {
            ans.pb( mp(1, L) );
            --k;    
        }
    }
    if(n > 1) {
        if(k) {
            ans.pb( mp( min(k, n-1), U ) );
            k = max(0, k-n+1);
        }
    }
    cout << ans.size() << '\n';
    for(auto [i, c]: ans) {
        cout << i << ' ' << c << '\n';
    }
}

int main(){
    FAST;
    solve();
    return 0;
}