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
int T, b;

vector<int> transform(vector<int> &a, int r, int c) {
    if(r) {
        reverse(all(a));
    }
    if(c) {
        for(auto &i: a) {
            i = (!i);
        }
    }
    return a;
}

void solve() {
    int q = 1;
    vector<int> a(b);
    int l = 1, r = b;
    int si = 0, di = 0;
    while((si == 0 || di == 0) && q <= b) {
        int x;
        if(q&1) {
            x = l++;
        } else {
            x = r--;
        }
        cout << 1 << ' ' << x << endl;
        cin >> a[x-1];
        if(x > b/2) {
            if(a[l-2] == a[x-1]) {
                si = l-1;
            } else {
                di = x;
            }
        }
        // if(a[x-1] == 'N') {
        //     exit(0);
        // }
        ++q;
    }
    // cout <<mp('s', 'd') << mp(si,di) << '\n';
    int found = 0, comp = 0, rev = 0;
    V<bool> known(100, false);
    int rem = (q-1)%10;
    if(!rem) rem = 10;
    // cout << rem << "r ";
    for(int i = 0; i*2 < rem; ++i) {
        known[l-2-i] = true;
        known[r+i] = true;
        // cout << mp(l-1-i, r+1+i);
    }
    found = rem;
    l = 0;
    int s, d;
    while(found < b) {
        // cout << a;
        rev = 0;
        comp = 0;
        if(q%10 == 1) {
            if(si) {
                cout << 1 << ' ' << si << endl;
                ++q;
                cin >> s;
                // if(s == 'N') exit(0);
            } else {
                s = -1;
            }
            if(di) {
                cout << 1 << ' ' << di << endl;
                ++q;
                cin >> d;
                // if(d == 'N') exit(0);
            } else {
                d = -1;
            }
            if(d == -1) {
                if(a[si-1] == s) {
                    comp = 0;
                    rev = 0;
                } else {
                    comp = 1;
                    rev = 0;
                }
            } else if(s == -1) {
                if(a[di-1] == d) {
                    rev = 0;
                    comp = 0;
                } else {
                    rev = 1;
                    comp = 0;
                }
            } else if(a[si-1] == s) {
                comp = 0;
                if(a[di-1] == d) {
                    rev = 0;
                } else {
                    rev = 1;
                }
            } else {
                comp = 1;
                if(a[di-1] == d) {
                    rev = 1;
                } else {
                    rev = 0;
                }
            }
            a = transform(a, rev, comp);
        } else {
            if(!known[l]) {
                cout << 1 << ' ' << l+1 << endl;
                ++q;
                int p;
                cin >> p;
                // if(p == 'N') exit(0);
                a[l] = p;
                ++found;
            }
            ++l;
        }
    }
    for(int i = 0; i < b; ++i) {
        cout << a[i];
    }
    cout << endl;
    char c;
    cin >> c;
    if(c == 'N') {
        exit(0);
    }
}

int main(){
    FAST;
    cin >> T >> b;
    loop(i, 1, T+1) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}