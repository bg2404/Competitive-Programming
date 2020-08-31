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

V<bool> is_prime;

void sieve(int n) {
    is_prime = V<bool>(n+1,true);
    is_prime[0] = is_prime[1] = false;
    for(int p = 2; p*p <= n; ++p) {
        if(is_prime[p]) {
            for(int i = p*p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
}

// This implementation is O(n).
// It also provides a list of prime and factorization for numbers in range [1, n]
V<int> lp;
V<int> prime;

void sieve2(int n) {
    lp.assign(lp.size(), 0);
    lp[1] = 1;
    for(int i = 2; i <= n; ++i) {
        if(lp[i] == 0) {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j = 0; j < prime.size() && pr[j] <= lp[i] && i*pr[j] <= n; ++j) {
            lp[i*pr[j]] = pr[j];
        }
    }
}

int main(){
    sieve(maxn);
    for(int i = 0; i < 10; ++i) {
        for(int j = 1; j < 11; ++j) {
            if(is_prime[i*10+j]) {
                cout << 'O' << ' ';
            } else {
                cout << 'X' << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}