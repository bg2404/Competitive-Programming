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
const ll maxn = 4e5+1;
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

void add(V<int> &arr, int N, int lo, int hi, int val) 
{ 
    arr[lo] += val; 
    if (hi != N - 1) 
       arr[hi + 1] -= val; 
} 
  
//  Utility method to get actual array from operation array 
void updateArray(V<int> &arr, int N) 
{ 
    //  convert array into prefix sum array 
    for (int i = 1; i < N; i++) 
        arr[i] += arr[i - 1]; 
} 

V<int> cnt, pos;

void solve(){
    int n, k;
    cin >> n >> k;
    V<int> a(n);
    loop(i, 0, n) {
        cin >> a[i];
    }
    int minp, maxp;
    cnt = pos = V<int> (2*k+1, 0);
    for(int i = 0, j = n-1; i < j; ++i, --j) {
        maxp = a[i] + a[j] - min(a[i], a[j]) + k;
        minp = a[i] + a[j] - max(a[i], a[j]) + 1;
        ++cnt[a[i] +a[j]];
        add(pos, pos.size(), minp, maxp, 1);
    }
    // cout << pos << '\n';
    updateArray(pos, pos.size());
    // cout << cnt << ' ' << pos << '\n';
    int ans = n/2 - cnt[k+1];
    loop(i, 2, 2*k+1) {
        int t = n - pos[i] - cnt[i];
        ans = min(ans, t);
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