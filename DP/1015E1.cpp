//https://codeforces.com/problemset/problem/1015/E1

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

int n, m, c, num;
string grid[1000];
int ans[1000][1000], cover[1000][1000];

int main(){
    FAST;
    cin >> n >> m;
    loop(i, 0, n) {
        cin >> grid[i];
        loop(j, 0, m) {
            if(grid[i][j] == '.') {
                cover[i][j] = 1;
            }
        }
    }

    loop(i, 0, n) {
        loop(j, 0, m) {
            // cout << i << ' ' << j << ' ' << grid[i][j] << '\n';
            int k = 0;
            if(grid[i][j] == '*') {
                for(k = 1; j + k < m && j - k >= 0 && i + k < n && i - k >= 0; ++k) {
                    // cout << k << ' ';
                    c = 0;
                    if(grid[i+k][j] == '*') {
                        ++c;
                    }
                    if(grid[i-k][j] == '*') {
                        ++c;
                    }
                    if(grid[i][j+k] == '*') {
                        ++c;
                    }
                    if(grid[i][j-k] == '*') {
                        ++c;
                    }
                    // cout << c << "| ";
                    if(c == 4) {
                        cover[i][j] = cover[i+k][j] = cover[i-k][j] = cover[i][j+k] = cover[i][j-k] = 1;
                        ans[i][j]++;
                    } else {
                        break;
                    }
                }
            }
            if(ans[i][j] > 0) {
                ++num;
            }
            // cout << '\n';
        }
    }

    bool pos = true;
    loop(i, 0, n) {
        loop(j, 0, m) {
            if(cover[i][j] == 0) {
                pos = false;
                break;
            }
        }
        if(!pos) {
            break;
        }
    }

    if(pos) {
        cout << num << '\n';
        loop(i, 0, n) {
            loop(j, 0, m) {
                if(ans[i][j] > 0) {
                    cout << i+1 << ' ' << j+1 << ' ' << ans[i][j] << '\n';
                }
            }
        }
    } else {
        cout << "-1\n";
    }
    return 0;
}