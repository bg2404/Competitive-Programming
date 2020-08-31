//https://codeforces.com/contest/1303/problem/D
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

V<int> to_binary(ll n) {
    V<int> v(64, 0);
    int i = 0;
    while(n) {
        v[i++] = n&1;
        n = n >> 1;
    }
    return v;
}

void solve(){
    long long n, a;
    int m;
    cin >> n >> m;
    V<int> bin = to_binary(n);
    V<int> cnt(33, 0);
    loop(i, 0, m) {
        cin >> a;
        ++cnt[log2(a)];
    }
    long long sum = 0, cur = 1;
    int div = 0;
    // cout << cnt << '\n';
    loop(i, 0, 33) {
        if(bin[i]) {
            if(sum >= cur) {
                sum -= cur;
            } else {
                if(cnt[i]) {
                    --cnt[i];
                } else {
                    bool flag = false;
                    loop(j, i+1, 33) {
                        if(cnt[j]) {
                            --cnt[j];
                            loopr(k, j-1, i) {
                                ++cnt[k];
                                ++div;
                            }
                            flag = true;
                            break;
                        }
                    }
                    if(!flag) {
                        cout << -1 << '\n';
                        return;
                    }
                }
            }
        }
        sum += cnt[i]*cur;
        cnt[i] = 0;
        cur = cur << 1;
        // cout << cnt << ' ' << sum << '\n';
    }
    cout << div << '\n';
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