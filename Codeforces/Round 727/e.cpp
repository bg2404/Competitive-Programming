#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define F_OR(i, a, b, s) for (ll i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(_VA_ARGS_, F_OR4, F_OR3, F_OR2, F_OR1)
#define forz(...) F_ORC(_VA_ARGS) \
(VA_ARGS_)
#define each(x, a) for (auto& x : a)
#define debug(x) cerr << #x << '=' << (x) << endl;
#define debugp(x) cerr << #x << "= {" << (x.first) << ", " << (x.second) << "}" << endl;
#define debug2(x, y) cerr << "{" << #x << ", " << #y << "} = {" << (x) << ", " << (y) << "}" << endl;
#define debugv(v)                          \
    {                                      \
        cerr << #v << " : ";               \
        for (auto x : v) cerr << x << ' '; \
        cerr << endl;                      \
    }
#define onBits(x) __builtin_popcount(x)

#define INF LLONG_MAX
#define F first
#define S second
#define pb push_back
#define pq priority_queue
#define vt vector
#define ar array
#define lb lower_bound
#define ub upper_bound
#define mp make_pair

#define mod ll(1e9 + 7)
#define nod ll(998244353)
#define all(lf) lf.begin(), lf.end()
#define kira ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

ll power(ll x, ll y, ll m = mod) {
    x = x % m;
    if (y == 0) return 1LL;
    if (y % 2) return (x * power((x * x) % m, y / 2, m)) % m;
    return power((x * x) % m, y / 2, m);
}
ll modInv(ll x, ll m = mod) {
    return power(x, m - 2, m);
}

//ll u, v, w;
//vt<vt<ll>> adj[mxN];
//void init()
//{
//    forz(i,n) vis[i]=0, adj[i].clear();
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const ll mxN = 1e5, mxM = 5e3;

struct node {
    ll complete, left, right, total;
};

ll n, m, k, r;
ll h[mxN], d[mxN], pref[mxN], suff[mxN];

ar<ll, 4> t[mxN * 4];

void build(ll l, ll r, ll z) {
    if (l == r) {
        t[z][2] = h[l] + d[l];
        t[z][1] = h[l];
        t[z][0] = 0LL;
        t[z][3] = d[l];
    }

    ll mid = (l + r) / 2;
    build(l, mid, 2 * z);
    build(mid + 1, r, 2 * z + 1);

    t[z][3] = t[2 * z][3] + t[2 * z + 1][3];
    t[z][1] = max(t[z * 2][1], t[z * 2][3] + t[z * 2 + 1][1]);
    t[z][2] = max(t[z * 2][2], t[z * 2 + 1][3], t[z * 2 + 1][2]);
    t[z][0] = max(max(t[2 * z][0], t[2 * z + 1][0]), t[2 * z][2] + t[z * 2 + 1][1]);
}

ar<ll, 4> query(ll l, ll r, ll tl, ll tr, ll z) {
    ar<ll, 4> temp = {0LL, 0LL, 0LL, 0LL};
    if (tl > tr) return temp;
    if (tl == l and r == tr) {
        return t[z];
    }
    ll mid = (l + r) / 2;
    ar<ll, 4> t1 = query(l, mid, tl, min(mid, tr), 2 * z), t2 = query(mid + 1, r, max(tl, mid + 1), tr, 2 * z + 1);
    temp[3] = t1[3] + t2[3];
    temp[1] = max(t1[1], t1[3] + t2[1]);
    temp[2] = max(t1[2], t2[3], t2[2]);
    temp[0] = max(max(t1[0], t2[0]), t1[2] + t2[1]);
    return temp;
}

void solve() {
    //Look at the limits dummy :\ O
    cin >> n >> m;
    forz(n) cin >> d[i];
    forz(n) cin >> h[i];

    build(0, n - 1, 1);

    ll curr = h[0];
    pref[0] = curr;
    forz(i, 1, n) {
        curr += d[i - 1] + h[i];
        pref[i] = max(curr, pref[i - 1]);
    }
    curr = d[n - 1] + h[n - 1];
    suff[n - 1] = curr;
    forz(i, n - 2, -1, -1) {
        curr += d[i] + h[i];
        suff[i] = max(suff[i + 1], curr);
    }
    ll a, b;
    forz(m) {
        cin >> a >> b;
        a--, b--;
        if (a < b) {
            if (a == 0) {
                cout << query(0, n - 1, b + 1, n - 1, 1)[0] << '\n';
            } else if (b == n - 1) {
                cout << query(0, n - 1, 0, a - 1, 1)[0] << '\n';
            } else {
                cout << max(max(query(0, n - 1, b + 1, n - 1, 1)[0], query(0, n - 1, 0, a - 1, 1)[0]), pref[a - 1] + suff[b + 1]);
            }
        } else {
            cout << query(0, n - 1, b + 1, a - 1, 1)[0] << '\n';
        }
    }
}

int32_t main() {
    kira;
    ll T = 1;
    // cin>>T;
    forz(i, 1, T + 1) {
        // cout<<"Case #"<<i<<": ";
        solve();
        // cout<<endl;
    }
}