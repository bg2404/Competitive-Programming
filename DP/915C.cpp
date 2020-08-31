//https://codeforces.com/problemset/problem/915/C

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

vector<int> countOf(10,0), bdig;

void swap_digits(ll &num, int i, int j) {
    stringstream ss;
    ss << num;
    string str = ss.str();
    swap(str[i], str[j]);
    ss.str("");
    ss << str;
    ss >> num;
}

int count_digits(ll num) {
    int d = 0;
    if(num == 0) {
        return 1;
    }
    while(num > 0) {
        ++d;
        num /= 10;
    }
    return d;
}

void sort_num(ll &num, int b = 0) {
    vector<int> digits;
    while(num > 0) {
        digits.push_back(num%10);
        num /= 10;
    }
    reverse(all(digits));
    sort(b + all(digits));
    loopr(i, digits.size()-1, 0) {
        num *= 10;
        num += digits[i];
    }
}

bool isPossible(ll a, string b, int d) {
    string b_ = b;
    b_ = b_ + to_string(d);
    for(int i = 0; i <= 9; ++i) {
        for(int j = 0; j < countOf[i]; ++j) {
            b_ = b_ + to_string(i);
        }
    }
    stringstream ss;
    ss << b_;
    ll c;
    ss >> c;
    ss.str("");
    if(c > a) {
        return false;
    }
    return true;
}

int main(){
    ll a, b;
    cin >> a >> b;
    int da = count_digits(a);
    int db = count_digits(b);
    ll temp = a;
    while(temp) {
        ++countOf[temp%10];
        temp /= 10;
    }
    temp = b;
    while(temp) {
        bdig.pb(temp%10);
        temp /= 10;
    }
    string ans = "";
    for(int i = 0; i < bdig.size(); ++i) {
        for(int j = 9; j >= 0; --j) {
            if(countOf[j]) {
                --countOf[j];
                if(isPossible(b, ans, j)) {
                    ans = ans + to_string(j);
                    break;
                } else {
                    ++countOf[j];
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}