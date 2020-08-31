#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define MOD2 998244353
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;++i)
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

int lcm(int a, int b) {
    return (a*b)/(__gcd(a, b));
}

void solve(){
    int a, b, q;
    cin >> a >> b >> q;
    if(a > b) {
        swap(a, b);
    }
    while(q--) {
        ll l, r, sl;
        cin >> l >> r;
        if(a == b) {
            cout << 0 << ' ';
            continue;
        }
        sl = l;
        long long ans = 0;
        if(l < b) {
            ans += min(b-l, r-l+1);
        }
        // cout << ans << '\n';
        l = max((ll)b, l);
        long long m = lcm(a, b);
        long long s = (l/m + (l%m != 0))*m;
        long long e = (r/m)*m;
        if(l%m && l != b) {
            long long bs = (l/m)*m;
            long long y = bs + b-1;
            ans += min(max(0LL, y-l+1), r-l+1);
            l = max(l, y);
            // cout << y << ' ' << ans << ' ';
        }
        // cout << e << ' ' << s << ' ';
        long long cnt = 0;
        if(e >= s) {
            cnt = (e-s)/m+1;
        }
        // cout <<"cnt = " << cnt << ' ';
        if(cnt) {
            ans += (cnt-1)*b;
            long long x = min(e+b-1, r);
            ans += x-e+1;
        }
        // cout << ans << '\n';
        ans = (r-sl+1) - ans;
        cout << ans << ' ';
    }
    cout << '\n';
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