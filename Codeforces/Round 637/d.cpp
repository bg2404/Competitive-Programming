//https://codeforces.com/contest/1341/problem/D
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

string num[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
map<string, int> v;
map<string, int> mv[8];

int value(string s) {
    if(num[v[s]] == s) {
        return v[s];
    }
    return -1;
}

int max_val(string &s, int k) {
    if(mv[k].count(s)) {
        return mv[k][s];
    }
    int cnt = 0;
    loopr(i, 9, 0) {
        cnt = 0;
        string t = num[i];
        loop(j, 0, 7) {
            if(s[j] != t[j]) {
                if(t[j] == '1')
                    ++cnt;
                else {
                    cnt = -1;
                    break;
                }
            }
        }
        if(cnt == k) {
            return mv[k][s] = i;
        }
    }
    return mv[k][s] = -1;
}
 

int diff(int n, string o) {
    string s = num[n];
    int c = 0;
    loop(i, 0, 7) {
        if(s[i] != o[i]) {
            ++c;
        }
    }
    return c;
}

int main(){
    // FILE_READ_OUT
    loop(i, 0, 10) {
        v[num[i]] = i;
    }
    int arr[7];
    // generateAllBinaryStrings(7, arr, 0);

    int n, k;
    scanf("%d %d", &n, &k);
    V<string> s(n);
    char str[8];
    for(auto &i: s) {
        scanf("%s", str);
        i = string(str);
        // cout << value(i);
    }
    // cout << '\n';
    
    V<V<bool> > dp(k+1, V<bool>(n, false));

    loope(i, 0, k) {
        if(i < 8) {
            if(max_val(s[n-1], i) >= 0) {
                dp[i][n-1] = true;
            }
        }
        loopr(j, n-2, 0) {
            loop(x, 0, 8) {
                if(i-x >= 0 && dp[i-x][j+1] == true && max_val(s[j], x) >= 0) {
                    dp[i][j] = true;
                    break;
                }
            }
        }
    }
    // for(auto r: dp) {
    //     for(auto c: r) {
    //         cout << setw(3) << c << ' ';
    //     }
    //     cout << '\n';
    // }

    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j <= k; ++j) {
    //         cout << dp[j][i] << ' ';
    //     }
    //     cout << '\n';
    // }

    if(dp[k][0] == false) {
        cout << -1 << '\n';
    } else {
        int d = k;
        loop(i, 0, n-1) {
            int x = -1, y = 0;
            loop(j, 0, 8) {
                if(d-j >= 0 && dp[d-j][i+1]) {
                    if(x < max_val(s[i], j)) {
                        x = max_val(s[i], j);
                        y = j;
                    }
                }
            }
            d -= y;
            cout << x;
        }
        cout << mv[d][s[n-1]] << '\n';
    }

    return 0;
}