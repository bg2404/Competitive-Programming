//https://codeforces.com/problemset/problem/919/D
#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
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

int n, m;
string str;
vector<vector<int>> adj, dp;
vector<int> color;
V<PII> indegree;

bool hasCycle(int s = 0){
    color[s] = 1;
    bool ans = false;
    for(auto &i: adj[s]) {
        if(color[i] == 0) {
            ans = ans | hasCycle(i);
        }
        if(color[i] == 1) {
            ans = true;
        }
    }
    color[s] = 2;
    return ans;
}

vector<bool> visited;
void solve(int s){
    int c = str[s] - 'a';
    visited[s] = true;
    for(auto &i: adj[s]) {
        if(!visited[i]) solve(i);
        loop(j, 0, 26) {
            dp[s][j] = max(dp[s][j], dp[i][j]);
        }
    }
    ++dp[s][c];
}

int main(){
    FAST;
    int u, v;
    cin >> n >> m;
    cin >> str;
    adj = vector<vector<int> > (n, vector<int>());
    dp = vector<vector<int> > (n, vector<int>(26,0));
    color = vector<int> (n, 0);
    indegree = V<PII>(n,{0,0});
    visited = vector<bool> (n, false);
    for(int i = 0; i < n; ++i) {
        indegree[i].second = i;
    }
    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        ++indegree[v-1].first;
    }

    bool cycle = 0;
    for(int i  = 0; i < n; ++i) {
        if(color[i] == 0) {
            if(hasCycle(i)) {
                cycle = 1;
                break;
            }
        }
    }

    if(cycle) {
        cout << -1 << '\n';
        return 0;
    }

    sort(all(indegree));
    for(int i = 0; i < n && indegree[i].first == 0; ++i) {
        solve(indegree[i].second);
    }

    int ans = 0;
    for(auto &r: dp) {
        for(auto &c: r) {
            ans = max(c, ans);
        }
    }
    
    cout << ans << '\n';

    return 0;
}