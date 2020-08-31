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
    int n;
    cin >> n;
    V<int> a(n);
    V<V<int> > cnt(200, V<int> (n, 0));
    loop(i, 0, n) {
        cin >> a[i];
        ++cnt[a[i]-1][i];
    }
    loop(i, 0, 200) {
        loop(j, 1, n) {
            cnt[i][j] = cnt[i][j-1] + cnt[i][j];
        }
    }
    // cout << cnt << '\n';
    int ans = 0;
    for(int i = 0; i < 200; ++i) {
        int j = 0, k = n-1;
        int temp = 0;
        while(j < k) {
    //         cout << j << '\n';
            while(a[j] != i+1 && j < n) {
                ++j;
            }
            while(a[k] != i+1 && k > j) {
                --k;
            }
            // cout << mp(j, k);
            if(j >= k || j >= n) {
                break;
            }
            ++temp;
            loop(m, 0, 200) {
                int tmp;
                if(k) {
                    tmp = cnt[m][k-1];
                }
                if(1) {
                    tmp -= cnt[m][j];
                }
                // cout << tmp << ' ';
                ans = max(ans, 2*temp + tmp);
            }
            ++j; --k;
        }
        
    }
    loop(i, 0, 200) {
        ans = max(ans, cnt[i][n-1]);
    }
    cout << ans << '\n';
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