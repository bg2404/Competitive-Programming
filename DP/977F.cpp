//https://codeforces.com/problemset/problem/977/F
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
const ll maxn = 2e5;
const ll inf = 1e9;
const double pi = acos(-1);

ostream& operator<<(ostream& o, PII &a) {
    o << "(" << a.first << ", " << a.second << ")";
}

int n, ans = 0;
int a[maxn];
PII dp[maxn];
map<int,int> li;
map<int,int> max_len;
int main(){

    FAST;
    #ifndef ONLINE_JUDGE
        FILE_READ_IN;
    #endif
    int n;
    cin >> n;
    loop(i, 0, n) {
        cin >> a[i];
        int ml = max_len[a[i]-1], lidx = li[a[i]-1];
        ans = max(ans, ml+1);
        dp[i] = mp(ml + 1, lidx);
        max_len[a[i]] = ml+1;
        li[a[i]] = i+1;
        // cout << i << ' ' << dp[i] << '\n';
    }

    cout << ans << '\n';
    int i;
    for(i = n-1; i >= 0; --i) {
        if(dp[i].first == ans) {
            break;
        }
    }

    stack<int> st;
    while(i >= 0) {
        st.push(i+1);
        i = dp[i].second-1;
    }
    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << '\n';

    return 0;
}