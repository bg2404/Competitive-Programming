#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define MOD2 998244353
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;++i)
#define loope(i,a,b) for(int i=a;i<=b;++i)
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

int n, m;
V<V<bool> > visited;
V<string> grid;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

void dfs(int x = 0, int y = 0) {
    visited[x][y] = true;
    loop(i, 0, 4) {
        int u = x+dx[i];
        int v = y+dy[i];
        if(u < n && u >= 0 && v < m && v >= 0 && !visited[u][v] && grid[u][v] == '#') {
            dfs(u, v);
        }
    }
}

bool satisfiesRowColCond() {
    bool empty, er = false, ec = false;
    for(int i = 0; i < n; ++i) {
        empty = true;
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == '#') {
                empty = false;
                break;
            }
        }
        if(empty) {
            er = true;
            break;
        }
    }

    loop(j, 0, m) {
        empty = true;
        loop(i, 0, n) {
            if(grid[i][j] == '#') {
                empty = false;
            }
        }
        if(empty) {
            ec = true;
            break;
        }
    }
    return er == ec;
}

int oneBlackGroupCol(int c) {
    int i = 0;
    while(i < n) {
        if(grid[i][c] != '.') {
            break;
        }
        ++i;
    }
    while(i < n) {
        if(grid[i][c] != '#') {
            break;
        }
        ++i;
    }
    while(i < n) {
        if(grid[i][c] != '.') {
            break;
        }
        ++i;
    }
    if(i < n) {
        return 0;
    }
    return 1;
}


int oneBlackGroupRow(int r) {
    int i = 0;
    while(i < m) {
        if(grid[r][i] != '.') {
            break;
        }
        ++i;
    }
    while(i < m) {
        if(grid[r][i] != '#') {
            break;
        }
        ++i;
    }
    while(i < m) {
        if(grid[r][i] != '.') {
            break;
        }
        ++i;
    }
    if(i < m) {
        return 0;
    }
    return 1;
}

void solve() {
    cin >> n >> m;
    visited = V<V<bool> >(n, V<bool>(m, false));
    grid = V<string>(n);
    loop(i, 0, n) {
        cin >> grid[i];
    }
    bool empty = true;
    loop(i, 0, n) {
        loop(j, 0, m) {
            if(grid[i][j] == '#') {
                empty = false;
                break;
            }
        }
        if(!empty) {
            break;
        }
    }
    if(empty) {
        cout << 0 << '\n';
        return;
    }

    if(!satisfiesRowColCond()) {
        cout << -1 << '\n';
        return;
    }
    loop(i, 0, n) {
        if(!oneBlackGroupRow(i)) {
            cout << -1 << '\n';
            return;
        }
    }
    loop(i, 0, m) {
        if(!oneBlackGroupCol(i)) {
            cout << -1 << '\n';
            return;
        }
    }
    int ans = 0;
    loop(i, 0, n) {
        loop(j, 0, m) {
            if(!visited[i][j] && grid[i][j] == '#') {
                ++ans;
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    FAST;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}