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

int n, k;
string s;

void solve(){
    cin >> n >> k;
    cin >> s;
    sort(all(s));
    // if(k == 1) {
    //     cout << s << '\n';
    //     return;
    // }
    if(s[0] != s[k-1]) {
        cout << s[k-1] << '\n';
        return;
    }
    string ans2 = s.substr(k-1, n-k+1);
    int cnt = 0;
    map<char, bool> before;
    loop(i, 0, n) {
        if(!before[s[i]]) {
            ++cnt;
            before[s[i]] = true;
        }
    }
    if(k == n || (s[k-1] == s[k] && cnt > 1) || cnt > 2) {
        cout << ans2 << '\n';
        // cout << '@';
        return;
    }
    V<string> vs(k, string(n/k+1, ' '));
    for(int i = 0, x = 0; i < n; ++x) {
        for(int j = 0; j < k && i < n; ++j) {
            vs[j][x] = s[i];
            ++i;
        }
    }
    string ans = vs[0];
    for(int i = 0; i < k; ++i) {
        int j = 0;
        for(; j < n/k+1; ++j) {
            if(vs[i][j] == ' ') {
                break;
            }
        }
        ans = max(ans, vs[i].substr(0, j));
    }
    // cout << vs << '\n';
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