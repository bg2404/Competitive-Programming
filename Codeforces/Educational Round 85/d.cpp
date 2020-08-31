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

pair<int, int> getLocation(ll n, ll l) {
    ll b_no = 0, pos, sum = 0;
    while(sum < l) {
        ++b_no;
        sum += 2*(n-b_no);
        sum += b_no == n;
    }
    if(b_no == n) {
        pos = 1;
    } else {
        pos = l - sum + 2*(n-b_no);
    }
    return {b_no, pos};
}

void printAns(int n, int bno, int s, int e) {
    if(bno == n) {
        cout << 1 << ' ';
        return;
    }
    loop(i, s, e+1) {
        if(i & 1) {
            cout << bno << ' ';
        } else {
            cout << bno + i/2 << ' ';
        }
    }
}

void solve(){
    ll n;
    ll l, r;
    cin >> n >> l >> r;
    PII lloc = getLocation(n,l), rloc = getLocation(n,r);
    // cout << lloc << ' ' << rloc << '\n';
    if(lloc.F == rloc.F) {
        printAns(n, lloc.F, lloc.S, rloc.S);
        cout << '\n';
    } else {
        printAns(n, lloc.F, lloc.S, 2*(n-lloc.F));
        loop(i, lloc.F+1, rloc.F) {
            printAns(n, i, 1, 2*(n-i));
        }
        printAns(n, rloc.F, 1, rloc.S);
        cout << '\n';
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