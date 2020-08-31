//https://codeforces.com/problemset/problem/766/C
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

vector<vector<int> > ways(1000, vector<int>(1000,0)), lenp(1000, V<int>(1000,0)), nums(1000, V<int>(1000,0));
int main(){
    FAST;
    #ifndef ONLINE_JUDGE
        FILE_READ_IN;
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;;
    vector<int> maxl(26);
    loop(x, 0, 26) {
        cin >> maxl[x];
    }
    ways[0][0] = 1;
    lenp[0][0] = maxl[s[0]-'a'];
    nums[0][0] = 1;
    int max_subs = 1, min_subs = INT_MAX, num_ways = 0;
    for(int i = 1; i < n; ++i) {
        // cout << i << ' ';
        nums[i][0] = inf;
        ways[i][0] = 0;
        for(int j = 0; j < n; ++j) {
            // cout << ways[i-1][j] << ' ';
            ways[i][0] = (ways[i][0] + ways[i-1][j]) % MOD;
            if(nums[i-1][j] > 0) {
                nums[i][0] = min(nums[i][0], nums[i-1][j]);
            }
        }
        // cout << '\n';
        ++nums[i][0];
        lenp[i][0] = maxl[s[i]-'a'];
        for(int j = 1; j < maxl[s[i]-'a']; ++j) {
            lenp[i][j] = 0;
            ways[i][j] = 0;
            nums[i][j] = 0;
            if(lenp[i-1][j-1] > j) {
                max_subs = max(max_subs, j+1);
                lenp[i][j] = min(lenp[i-1][j-1], maxl[s[i]-'a']);
                ways[i][j] = ways[i-1][j-1];
                nums[i][j] = nums[i-1][j-1];
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        if(nums[n-1][i] > 0) {
            min_subs = min(min_subs, nums[n-1][i]);
            num_ways = (num_ways + ways[n-1][i]) % MOD;
        }
    }

    cout << num_ways << '\n' << max_subs << '\n' << min_subs << '\n';
    return 0;
}