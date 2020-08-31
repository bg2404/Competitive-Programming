#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
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

V<int> prime;

void sieve(int n) {
    V<bool> mark(n+1, true);
    mark[0] = mark[1] = false;
    for(int p = 2; p*p <= n; ++p) {
        if(mark[p]) {
            for(int i = p*p; i <= n; i += p) {
                mark[i] = false;
            }
        }
    }
    for(int i = 2; i <= n; ++i) {
        if(mark[i]) {
            prime.pb(i);
        }
    }
}

void segmentedSieve(int n) {
    int limit = floor(sqrt(n)) + 1;
    sieve(limit);
    int low = limit, high = 2*limit;
    V<int> p;
    while(low < n) {
        if(high > n) {
            high = n;
        }

        V<bool> mark(limit+1, true);
        loop(i, 0, prime.size()) {
            int lowLim = floor(low/prime[i]) * prime[i];
            if(lowLim < low) {
                lowLim += prime[i];
            }
            loops(j, lowLim, high, prime[i]) {
                mark[j-low] = false;
            }            
        }

        loop(i, low, high) {
            if(mark[i-low]) {
                p.pb(i);
            }
        }

        low += limit;
        high += limit;
    }
    for(auto x: p) {
        prime.pb(x);
    }
}

int main() {
    segmentedSieve(200);
    for(auto p: prime) {
        cout << p << ' ';
    }
    cout << '\n';
    return 0;
}