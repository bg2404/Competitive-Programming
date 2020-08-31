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

V<V<int> > a, b;
int main(){
    FAST;
    int n, m;
    cin >> n >> m;
    a = b = V<V<int> >(n, V<int>(m));
    loop(i, 0, n) {
        loop(j, 0, m) {
            cin >> a[i][j];
        }
    }
    loop(i, 0, n) {
        loop(j, 0, m) {
            cin >> b[i][j];
        }
    }
    if(n < 2 || m < 2) {
        loop(i, 0, n) {
            loop(j, 0, m) {
                if(a[i][j] != b[i][j]) {
                    cout << "No\n";
                    return 0;
                }
            }
        }
        cout << "Yes\n";
        return 0;
    }

    loop(i, 0, n-1) {
        loop(j, 0, m-1) {
            if(a[i][j] != b[i][j]) {
                a[i][j+1] ^= 1;
                a[i+1][j] ^= 1;
                a[i+1][j+1] ^= 1;
                a[i][j] ^= 1;
            }
        }
        if(a[i][n-1] != b[i][n-1]) {
            cout << "No\n";
            return 0;
        }
    }
    loop(i, 0, m) {
        if(a[n-1][i] != b[n-1][i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}

/*

1 1 0 1 0 1 1               1 1 0 1 0 1 1
0 1 1 0 1 0 0               0 1 1 0 1 0 0
1 1 0 1 0 0 1               1 1 0 1 0 0 1
1 0 1 0 0 1 0               1 0 1 0 0 1 0
0 1 1 0 1 0 0               0 1 1 0 1 0 0
0 1 1 1 1 0 1               0 1 1 1 1 0 1

*/