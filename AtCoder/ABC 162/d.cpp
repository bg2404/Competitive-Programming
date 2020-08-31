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

char getThird(char a, char b) {
    if(a > b) {
        swap(a,b);
    }
    if(a == 'B') {
        if(b == 'G') {
            return 'R';
        } else {
            return 'G';
        }
    }
    return 'B';
}

int main(){
    FAST;
    int n;
    string s;
    cin >> n >> s;
    V<int> lr(n, 0), lg(n, 0), lb(n, 0);
    for(int i = n-2; i; --i) {
        if(s[i+1] == 'R') {
            lr[i] = lr[i+1]+1;
            lg[i] = lg[i+1];
            lb[i] = lb[i+1];
        } else if(s[i+1] == 'G') {
            lr[i] = lr[i+1];
            lg[i] = lg[i+1]+1;
            lb[i] = lb[i+1];
        } else {
            lr[i] = lr[i+1];
            lg[i] = lg[i+1];
            lb[i] = lb[i+1]+1;
        }
    }
    ll ans = 0;
    loop(i, 0, n) {
        loop(j, i+1, n) {
            if(s[i] != s[j]) {
                char c = getThird(s[i], s[j]);
                int k = j + j-i;
                int t = k;
                if(c == 'R') {
                    k = lr[j];
                } else if(c == 'G') {
                    k = lg[j];
                } else {
                    k = lb[j];
                }
                // cout << ans << ' ';
                ans += k;
                if(t < n && s[t] == c) {
                    --ans;
                    // cout << -ans << ' ';
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}