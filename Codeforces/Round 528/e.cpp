//https://codeforces.com/contest/1087/problem/E
#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define MOD2 998244353
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

void solve(){
    int k;
    string s, a, b;
    cin >> k >> s >> a >> b;
    string t = string(s.size(), '0');
    string te = string(k, '0');
    V<V<int> > pos(26, V<int>() );
    map<char, bool> used;
    loop(i, 0, s.size() ) {
        pos[s[i]-'a'].pb(i);
    }
    bool found = false;
    int lpos = -1;
    char lposnext = 'a'-1;
    loop(i, 0, s.size()) {
        int c = s[i]-'a';
        char x = a[i];
        if(found) {
            if(te[c] == '0') {
                char d = 'a';
                while(used[d] && d < 'a'+k) {
                    ++d;
                }
                if(d >= 'a'+k) {
                    cout << "NO\n";
                    return;
                }
                te[c] = d;
                used[d] = true;
            }
        } else {
            if(te[c] == '0') {
                char d = x;
                while(used[d] && d < 'a'+k) {
                    ++d;
                }
                if(d >= 'a'+k) {
                    cout << "NO\n";
                    return;
                }
                te[c] = d;
                used[d] = true;
                found = (d>x);
                ++d;
                if(used[d] && d < 'a'+k) {
                    ++d;
                }
                if(d < 'a'+k) {
                    lpos = i;
                    lposnext = d;
                }
            } else {
                if(te[c] < x) {
                    used.clear();
                    te = string(k, '0');
                    loop(j, 0, lpos) {
                        used[a[j]] = true;
                        te[s[j]-'a'] = a[j];
                    }
                    te[s[lpos]-'a'] = lposnext;
                    used[lposnext] = true;
                    i = lpos;
                    found = true;
                } else if(te[c] > x) {
                    found = true;
                }
            }
        }
        // cout << lpos << ' ' << lposnext << '\n';
    }
    loop(i, 0, te.size()) {
        if(te[i] == '0') {
            loop(j, 0, 26) {
                if(!used[j+'a']) {
                    te[i] = 'a'+j;
                    used[j+'a'] = true;
                    break;
                }
            }
        }
    }
    loop(i,0,s.size()) {
        int c = s[i]-'a';
        t[i] = te[c];
    }
    if(t > b || t < a) {
        // cout << t << ' ' << te << ' ';
        cout << "NO\n";
        return;
    }
    cout << "YES\n" << te << '\n';
}

int main(){
    FAST;
    // FILE_READ_IN
    // FILE_READ_OUT
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}