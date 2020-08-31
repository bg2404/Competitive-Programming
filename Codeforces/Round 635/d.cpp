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
#define FAST ios_base::sync_with_stdio(false);cin.tie();//cout.tie();
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

ull dist(ull a, ull b, ull c) {
    return (a-b)*(a-b) + (b-c)*(b-c) + (c-a)*(c-a);
}

ull solve2(V<ull> &r, V<ull> &g, V<ull> b) {
    ull ans = LONG_LONG_MAX;
    sort(all(r));
    sort(all(b));
    for(auto x: g) {
        auto r1 = lower_bound(all(r), x), r2 = upper_bound(all(r), x), r3 = r.end();
        auto b1 = lower_bound(all(b), x), b2 = upper_bound(all(b), x), b3 = b.end();
        if(*r1 > x || r1 == r.end()) {
            if(r1 != r.begin()) {
                r1 = r1 - 1;
            }
        }
        if(*b1 > x || b1 == b.end()) {
            if(b1 != b.begin()) {
                b1 = b1 - 1;
            }
        }
        if(*r1 == x && r1 != r.end()) {
            if(r1 != r.begin()) {
                swap(r1, r3);
                r1 = r3 - 1;
            }
        }
        if(*b1 == x && b1 != b.end()) {
            if(b1 != b.begin()) {
                swap(b1, b3);
                b1 = b3 - 1;
            }
        }
        ull temp;
        if(r1 != r.end()) {
            if(b1 != b.end()) {
                temp = dist(*r1, x, *b1);
                ans = min(ans, temp);
                //cout << "(1)";
                //cout << "(1)";
                //cout << mp(mp(*r1, x), mp(*b1, ans)) << ' ';
            }
            if(b2 != b.end()) {
                temp = dist(*r1, x, *b2);
                ans = min(ans, temp);
                //cout << "(1)";//cout << "(2)";
                //cout << mp(mp(*r1, x), mp(*b2, ans)) << ' ';
            }
            if(b3 != b.end()) {
                temp = dist(*r1, x, *b3);
                ans = min(ans, temp);
                //cout << "(1)";//cout << "(3)";
                //cout << mp(mp(*r1, x), mp(*b3, ans)) << ' ';
            }
        }
        if(r2 != r.end()) {
            if(b1 != b.end()) {
                temp = dist(*r2, x, *b1);
                ans = min(ans, temp);
                //cout << "(2)";//cout << "(1)";
                //cout << mp(mp(*r2, x), mp(*b1, ans)) << ' ';
            }
            if(b2 != b.end()) {
                temp = dist(*r2, x, *b2);
                ans = min(ans, temp);
                //cout << "(2)";//cout << "(2)";
                //cout << mp(mp(*r2, x), mp(*b2, ans)) << ' ';
            }
            if(b3 != b.end()) {
                temp = dist(*r2, x, *b3);
                ans = min(ans, temp);
                //cout << "(2)";//cout << "(3)";
                //cout << mp(mp(*r2, x), mp(*b3, ans)) << ' ';
            }   
        }
        if(r3 != r.end()) {
            if(b1 != b.end()) {
                temp = dist(*r3, x, *b1);
                ans = min(ans, temp);
                //cout << "(3)";//cout << "(1)";
                //cout << mp(mp(*r3, x), mp(*b1, ans)) << ' ';
            }
            if(b2 != b.end()) {
                temp = dist(*r3, x, *b2);
                ans = min(ans, temp);
                //cout << "(3)";//cout << "(2)";
                //cout << mp(mp(*r3, x), mp(*b2, ans)) << ' ';
            }
            if(b3 != b.end()) {
                temp = dist(*r3, x, *b3);
                ans = min(ans, temp);
                //cout << "(3)";//cout << "(3)";
                //cout << mp(mp(*r3, x), mp(*b3, ans)) << ' ';
            }
        }
    }
    return ans;
}
void solve(){
    int nr, ng, nb;
    cin >> nr >> ng >> nb;
    V<ull> r(nr), g(ng), b(nb);
    for(auto &i: r) {
        cin >> i;
    }
    for(auto &i: g) {
        cin >> i;
    }
    for(auto &i: b) {
        cin >> i;
    }
    
    ull ans = solve2(r, g, b);
    ans = min(ans, solve2(r, b, g));
    ans = min(ans, solve2(g, r, b));

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