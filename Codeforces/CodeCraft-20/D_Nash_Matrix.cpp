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

V<V<PII> > inp;
V<V<char> > grid;

void bfs(PII s = mp(0,0)) {
    queue<PII> q;
    q.push(s);
    while(q.size()){
        PII u = q.front();
        q.pop();
        if(grid[u.F-1][u.S] == '.' && inp[u.F-1][u.S] == s) {
            grid[u.F-1][u.S] = 'D';
            q.push(mp(u.F-1, u.S));
        }
        if(grid[u.F+1][u.S] == '.' && inp[u.F+1][u.S] == s) {
            grid[u.F+1][u.S] = 'U';
            q.push(mp(u.F+1, u.S));
        }
        if(grid[u.F][u.S-1] == '.' && inp[u.F][u.S-1] == s) {
            grid[u.F][u.S-1] = 'R';
            q.push(mp(u.F, u.S-1));
        }
        if(grid[u.F][u.S+1] == '.' && inp[u.F][u.S+1] == s) {
            grid[u.F][u.S+1] = 'L';
            q.push(mp(u.F, u.S+1));
        }
    }
}

int main(){
    FAST;
    int n;
    cin >> n;
    inp = V<V<PII> >(n+2, V<PII>(n+2, mp(0,0)));
    grid = V<V<char> >(n+2, V<char>(n+2, '.'));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> inp[i][j].F >> inp[i][j].S;
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(grid[i][j] == '.') {
                if(mp(i, j) == inp[i][j]) {
                    grid[i][j] = 'X';
                } else if(mp(-1, -1) == inp[i][j]) {
                    if(grid[i-1][j] == '.' && inp[i-1][j] == mp(-1,-1)) {
                        grid[i-1][j] = 'D';
                        grid[i][j] = 'U';
                    } else if(grid[i+1][j] == '.' && inp[i+1][j] == mp(-1,-1)) {
                        grid[i][j] = 'D';
                        grid[i+1][j] = 'U';
                    } else if(grid[i][j-1] == '.' && inp[i][j-1] == mp(-1,-1)) {
                        grid[i][j-1] = 'R';
                        grid[i][j] = 'L';
                    } else if(grid[i][j+1] == '.' && inp[i][j+1] == mp(-1,-1)) {
                        grid[i][j] = 'R';
                        grid[i][j+1] = 'L';
                    } else if(inp[i-1][j] == mp(-1,-1)) {
                        grid[i][j] = 'U';
                    } else if(inp[i+1][j] == mp(-1,-1)) {
                        grid[i][j] = 'D';
                    } else if(inp[i][j-1] == mp(-1,-1)) {
                        grid[i][j] = 'L';
                    } else if(inp[i][j+1] == mp(-1,-1)) {
                        grid[i][j] = 'R';
                    } else {
                        cout << "INVALID\n";
                        // for(auto r:grid) {
                        //     cout << r << '\n';
                        // }
                        return 0;
                    }
                }
            }
        }
    }
    loop(i, 1, n+1) {
        loop(j, 1, n+1) {
            if(grid[i][j] == 'X') {
                bfs(mp(i,j));
            }
        }
    }
    loop(i, 1, n+1) {
        loop(j, 1, n+1) {
            if(grid[i][j] == '.') {
                cout << "INVALID\n";
                return 0;
            }
        }
    }
    // for(auto r: grid) {
    //     cout << r << 
    // }
    cout << "VALID" << '\n';
    loop(i, 1, n+1) {
        loop(j, 1, n+1) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
    return 0;
}