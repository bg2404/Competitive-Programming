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

V<V<PII>> rules(2);
int n, m;
bool checkRules() {
    int n = rules[0].size();
    int m = rules[1].size();
    loop(i, 0, n) {
        // cout << rules[0][i] << ' ';
        int x = rules[0][i].F, y = rules[0][i].S;
        loop(j, 0, m) {
            // cout << rules[1][j] << ' ';
            int a = rules[1][j].F, b = rules[1][j].S;
            if(x >= a && y <= b) {
                return false;
            }
        }
        // cout << '\n';
    }
    return true;
}

void coalesceIntervals() {
    if(rules[1].size() == 0) {
        return;
    }
    V<PII> intervals;
    sort(all(rules[1]));
    PII temp = rules[1][0];
    for(int i = 0; i < rules[1].size(); ++i) {
        if(rules[1][i].F <= temp.S) {
            temp.S = max(temp.S, rules[1][i].S);
        } else {
            intervals.pb(temp);
            temp = rules[1][i];
        }
    }
    intervals.pb(temp);
    rules[1] = intervals;
}

int main(){
    FAST;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int t, f, s;
        cin >> t >> f >> s;
        rules[t].pb(mp(f,s));
    }
    coalesceIntervals();
    if(checkRules()) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
        return 0;
    }
    V<int> ans(n+1, -inf);
    int v = 10*n, r = 0;
    for(int i = 0; i < rules[1].size(); ++i) {
        for(int j = rules[1][i].F;  j <= rules[1][i].S; ++j) {
            ans[j] = v;
        }
        if(i + 1 < rules[1].size()) {
            v -= rules[1][i+1].F - rules[1][i].S + 10;
        }
    }
    ans[0] = 100*n;
    for(int i = 1; i <= n; ++i) {
        if(ans[i] == -inf) {
            ans[i] = ans[i-1]-1;
        }
    }
    loop(i, 1, n+1) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}