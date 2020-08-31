//https://www.codechef.com/GHC32020/problems/XORSEQ

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

ll getXOR(ll n) {
    ll ret[] = {n, 1, n+1, 0};
    return ret[n%4];
}

ll getXOR(ll l, ll r) {
    return getXOR(r) ^ getXOR(l-1);
} 

set<ll> used;
set<PLL> used_range;

int main(){
    FAST;
    #ifndef ONLINE_JUDGE
        // FILE_READ_IN;
    #endif

    int n;
    cin >> n;

    int q;
    cin >> q;
    while(q--) {
        int c, x;
        cin >> c >> x;
        if(c == 1) {
            if(used.count(x) == 0) {
                used.emplace(x);
                bool lip = count_if(all(used_range), [x](PLL p){if(x-1 == p.S) return true; return false;});
                bool rip = count_if(all(used_range), [x](PLL p){if(x+1 == p.F) return true; return false;});
                if(lip) {
                    auto itr = find_if(all(used_range), [x](PLL p){if(x-1 == p.S) return true; return false;});
                    ll l = itr->F, r = itr->S;
                    if(rip) {
                        auto itr2 = find_if(all(used_range), [x](PLL p){if(x+1 == p.F) return true; return false;});
                        used_range.erase(itr2);
                        r = itr2->S;
                    } else {
                        r = x;
                    }
                    used_range.erase(itr);
                    used_range.emplace(mp(l,r));
                } else if(rip) {
                    auto itr = find_if(all(used_range), [x](PLL p){if(x+1 == p.F)return true; return false;});
                    ll l = itr->F, r = itr->S;
                    l = x;
                    used_range.erase(itr);
                    used_range.emplace(mp(l,r));
                } else {
                    used_range.emplace(mp(x,x));
                }
            }
        } else {
            bool ip = count_if(all(used_range), [x](PLL p){if(x >= p.F && x <= p.S) return true; return false;});
            ll l, r;
            if(ip) {
                auto itr = find_if(all(used_range), [x](PLL p){if(x >= p.F && x <= p.S) return true; return false;});
                l = itr->S+1;
            } else {
                l = x;
            }
            r = used_range.lower_bound(mp(l, 0))->S - 1LL;
            if(r == -1) {
                r = n;
            }
            // cout << mp(l ,r) << ' ';
            cout << getXOR(l, r) << '\n';
        }
    }

    return 0;
}