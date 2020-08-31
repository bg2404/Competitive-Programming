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

int MAX;
V<int> factor;
// V<int> pr;
V<int> active;
map<int, int> pu;
// void sieve(int n) {
//     V<bool> prime(n+1,true);
//     prime[0] = prime[1] = false;
//     for(int p = 2; p*p <= n; ++p) {
//         if(prime[p]) {
//             for(int i = p*p; i <= n; i += p) {
//                 prime[i] = false;
//             }
//         }
//     }
//     loop(i, 0, n+1) {
//         if(prime[i]) pr.pb(i);
//     }
// }

void generatePrimeFactors() 
{ 
    factor = V<int>(MAX);
    factor[1] = 1; 
  
    // Initializes all the positions with their value. 
    for (int i = 2; i < MAX; i++) 
        factor[i] = i; 
  
    // Initializes all multiples of 2 with 2 
    for (int i = 4; i < MAX; i += 2) 
        factor[i] = 2; 
  
    for (int i = 3; i * i < MAX; i++) { 
        if (factor[i] == i) { 
            for (int j = i * i; j < MAX; j += i) { 
                if (factor[j] == j) 
                    factor[j] = i; 
            } 
        } 
    } 
} 

int main(){
    FAST;
    int n,m;
    cin >> n >> m;
    MAX = n+1;
    active = V<int>(n+1);
    // sieve(n);
    generatePrimeFactors();
    while(m--) {
        char c;
        int h;
        cin >> c >> h;
        if(c == '+') {
            if(active[h]) {
                cout << "Already on\n";
            } else {
                bool skip = false;
                int t = h; 
                while(t > 1) {
                    int f = factor[t];
                    auto itr = pu.find(f);
                    if(itr != pu.end()) {
                        cout << "Conflict with " << itr->S << '\n';
                        skip = true;
                        break;
                    }
                    while(t % f == 0) {
                        t /= f;
                    }
                }
                // for(int i = 0; i < pr.size() && pr[i] <= h; ++i) {
                //     if(h % pr[i] == 0) {
                        
                //     }
                // }
                if(skip) {
                    continue;
                }
                active[h] = true;
                cout << "Success\n";
                t = h;
                while(t > 1) {
                    int f = factor[t];
                    auto itr = pu.find(f);
                    pu[f] = h;
                    while(t % f == 0) {
                        t /= f;
                    }
                }
                // for(int i = 0; i < pr.size() && pr[i] <= h; ++i) {
                //     if(h % pr[i] == 0) {
                //         pu[pr[i]] = h;
                //     }
                // }
            }
        } else {
            if(active[h]) {
                active[h] = false;
                cout << "Success\n";
                int t = h;
                while(t > 1) {
                    int f = factor[t];
                    auto itr = pu.find(f);
                    pu.erase(f);
                    while(t % f == 0) {
                        t /= f;
                    }
                }
            } else {
                cout << "Already off\n";
            }
        }
    }
    return 0;
}