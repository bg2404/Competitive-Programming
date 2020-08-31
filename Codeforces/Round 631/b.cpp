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

set<int> l, r, p;
V<int> a;
V<int> ans;
void solve(){
    int n;
    cin >> n;
    a = V<int>(n);
    l.clear();
    r.clear();
    r.clear();
    ans.clear();    
    loop(i, 0, n) {
        cin >> a[i];
    }
    int i;
    for(i = 0; i < n-1; ++i) {
        l.emplace(a[i]);
        if(l.size() == i+1 && *l.rbegin() == i + 1) {
            loop(j, i+1, n) {
                if(r.count(a[j])) {
                    p.emplace(a[j]);
                } else {
                    r.emplace(a[j]);
                }
            }
            if(r.size() == n-i-1 && *r.rbegin() == n-i-1) {
                ans.pb(i+1);
            }
            break;
        }
    }
    // cout << l << ' ' << r << '\n';
    
    int b = i+1;
    loop(i, b, n-1) {
        l.emplace(a[i]);
        if(p.count(a[i])) {
            p.erase(p.find(a[i]));
        } else {
            if(r.count(a[i])) {
                r.erase(r.find(a[i]));
            } else {
                cout << 0 << '\n';
                return;
            }
        }
        if(l.size() == i+1 && *l.rbegin() == i + 1) {
            if(r.size() == n-i-1 && *r.rbegin() == n-i-1) {
                ans.pb(i+1);
            }
        }
        // cout << l << ' ' << r << '\n';
    }

    cout << ans.size() << '\n';
    loop(i, 0, ans.size()) {
        cout << ans[i] << ' ' << n - ans[i] << '\n';
    }
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