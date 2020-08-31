//https://codeforces.com/contest/681/problem/C
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

int main(){
    FAST;
    int n;
    cin >> n;
    V<P<string, int> > inOp(n), ans;
    priority_queue<int, vector<int>, greater<int> > pq;
    loop(i, 0, n) {
        cin >> inOp[i].F;
        if(inOp[i].F == "removeMin") {
            inOp[i].S = -1;
            continue;
        }
        cin >> inOp[i].S;
    }
    loop(i, 0, n) {
        if(inOp[i].F == "insert") {
            ans.pb(inOp[i]);
            pq.push(inOp[i].S);
        } else if(inOp[i].F == "getMin") {
            while(!pq.empty() && pq.top() < inOp[i].S) {
                ans.pb(mp("removeMin", -1));
                pq.pop();
            }
            if(pq.empty()) {
                ans.pb(mp("insert", inOp[i].S));
                pq.push(inOp[i].S);
            } else if(pq.top() > inOp[i].S) {
                ans.pb(mp("insert", inOp[i].S));
                pq.push(inOp[i].S);
            }
            ans.pb(inOp[i]);
        } else {
            if(pq.empty()) {
                ans.pb(mp("insert", 1));
                pq.push(1);
            }
            ans.pb(inOp[i]);
            pq.pop();
        }
    }
    cout << ans.size() << '\n';
    loop(i, 0, ans.size()) {
        cout << ans[i].F;
        if(ans[i].F == "removeMin") {
            cout << '\n';
            continue;
        }
        cout << ' ' << ans[i].S << '\n';
    }
    return 0;
}