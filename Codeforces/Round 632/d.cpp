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
int n, k;
string s;
V<V<int> > moves;
int cnt = 0;

bool play() {
    V<int> move;
    for(int i = 0; i < n-1; ++i) {
        if(s[i] == 'R' && s[i+1] == 'L') {
            move.pb(i+1);
            swap(s[i], s[i+1]);
            ++i;
            ++cnt;
        }
    }
    if(move.size()) {
        moves.pb(move);
        return true;
    }
    // cout << s << ' ';
    return false;
}

int main(){
    FAST;
    cin >> n >> k >> s;
    while(play());
    if(cnt < k || moves.size() > k) {
        // cout << cnt << ' ' << moves.size() << '\n';
        cout << -1 << '\n';
        return 0;
    }
    int ans = moves.size();
    for(int i = 0; i < moves.size(); ++i) {
        if(ans == k) {
            cout << moves[i].size() << ' ';
            loop(j, 0, moves[i].size()) {
                cout << moves[i][j] << ' ';
            }
            cout << '\n';
        } else {
            if(moves[i].size() == 1) {
                cout << 1 << ' ' << moves[i][0] << '\n';
            } else {
                int t = 1;
                while(t < moves[i].size() && ans < k) {
                    cout << 1 << ' ' << moves[i][t-1] << '\n';
                    ++ans;
                    ++t;
                }
                cout << moves[i].size() - t + 1 << ' ';
                loop(j, t-1, moves[i].size()) {
                    cout << moves[i][j] << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}