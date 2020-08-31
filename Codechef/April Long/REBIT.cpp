#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 998244353
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

struct Item {
    char value;
    ll z;
    ll o;
    ll a;
    ll A;

    Item(char c) {
        value = c;
        z = o = a = A = 1;
    }
};

ll power(ll x, unsigned ll y, ll p = MOD2) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) {
            res = (res*1LL*x) % p;
        }
        y = y>>1;
        x = (x*1LL*x) % p;
    }
    return res;
}

int prec(char c) {
    if(c == '&') 
    return 3; 
    else if(c == '^')
    return 2; 
    else if(c == '|')
    return 1; 
    else
    return -1; 
}
 
string infixToPostfix(string s) { 
    std::stack<char> st; 
    st.push('N'); 
    int l = s.length(); 
    string ns; 
    for(int i = 0; i < l; i++) {
        if(s[i] == '#') {
            ns+=s[i];
        } else if(s[i] == '(') {
            st.push('(');
        } else if(s[i] == ')') {
            while(st.top() != 'N' && st.top() != '(') {
                char c = st.top();
                st.pop();
                ns += c;
            }
            if(st.top() == '(') {
                char c = st.top();
                st.pop();
            }
        } else{
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) { 
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }
    }
    while(st.top() != 'N') {
        char c = st.top();
        st.pop();
        ns += c;
    }
    return ns;
}

Item AND(Item i1, Item i2) {
    Item i('#');
    i.z = ((i1.z*(i2.o + i2.a + i2.A + i2.z))%MOD2 + ((i1.o + i1.a + i1.A)*i2.z)%MOD2 + (i1.a*i2.A + i1.A*i2.a)%MOD2)%MOD2;
    i.o = (i1.o * i2.o)%MOD2;
    i.a = (i1.o*i2.a + i1.a*i2.o + i1.a*i2.a)%MOD2;
    i.A = (i1.o*i2.A + i1.A*i2.o + i1.A*i2.A)%MOD2;
    return i;
}

Item OR(Item i1, Item i2) {
    Item i('#');
    i.z = (i1.z*i2.z)%MOD2;
    i.o = ((i1.o*(i2.z+i2.a+i2.A))%MOD2 + ((i1.z + i1.o + i1.a + i2.A)*i2.o)%MOD2 + (i1.a*i2.A + i1.A*i2.a)%MOD2)%MOD2;
    i.a = (i1.z*i2.a + i1.a*i2.a + i1.a*i2.z)%MOD2;
    i.A = (i1.z*i2.A + i1.A*i2.A + i1.A*i2.z)%MOD2;
    return i;
}

Item XOR(Item i1, Item i2) {
    Item i('#');
    i.z = ((i1.z*i2.z + i1.o*i2.o)%MOD2 + (i1.a*i2.a + i1.A*i2.A)%MOD2)%MOD2;
    i.o = ((i1.z*i2.o + i1.o*i2.z)%MOD2 + (i1.a*i2.A + i1.A*i2.a)%MOD2)%MOD2;
    i.a = ((i1.z*i2.a + i1.o*i2.A)%MOD2 + (i1.a*i2.z + i1.A*i2.o)%MOD2)%MOD2;
    i.A = ((i1.z*i2.A + i1.o*i2.a)%MOD2 + (i1.a*i2.o + i1.A*i2.z)%MOD2)%MOD2;
    return i;
}

void evaluatePostFix(string s) {
    stack<struct Item> st;
    int count = 0;
    int n = s.size();
    loop(i, 0, n) {
        if(s[i] == '#') {
            struct Item i('#');
            ++count;
            st.push(i);
        } else {
            struct Item i1 = st.top();
            st.pop();
            struct Item i2 = st.top();
            st.pop();
            switch(s[i]) {
                case '&': st.push(AND(i1, i2));
                          break;
                case '|': st.push(OR(i1, i2));
                          break;
                case '^': st.push(XOR(i1, i2));
                          break;
            }
        }
    }
    Item i = st.top();
    st.pop();
    ll z = i.z, o = i.o, a = i.a, A = i.A;
    ll den = power(4, count, MOD2);
    // ll den = 1;
    den = power(den, MOD2-2, MOD2);
    z = ((z*den)%MOD2+MOD2)%MOD2;
    o = ((o*den)%MOD2+MOD2)%MOD2;
    a = ((a*den)%MOD2+MOD2)%MOD2;
    A = ((A*den)%MOD2+MOD2)%MOD2;
    cout << z << ' ' << o << ' ' << a << ' ' << A << '\n';
}

void solve(){
    string s;
    cin >> s;
    s = infixToPostfix(s);..
    evaluatePostFix(s);
}

int main(){
    FAST;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}