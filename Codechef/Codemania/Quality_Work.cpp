#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod2 998244353
#pragma GCC optimize("-O2")
#define mod3 127
#define mod 1000000007
#define MAXN 1000000000
#define v32 vector<int>
#define v64 vector<lli>
#define v1024 vector<vector<int>>
#define v4096 vector<vector<lli>>
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
#define fd(x, y, z) for (lli x = y; x > z; x--)
#define lb lower_bound
#define ld long double
#define m64 map<lli, lli>
#define m32 map<int, int>
#define m64it map<lli, lli>::iterator
#define m32it map<int, int>::iterator
#define fastio                    \
ios_base::sync_with_stdio(0); \
cin.tie(0);                   \
cout.tie(0)
#define ist insert
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define p_q priority_queue
#define min_p_q priority_queue<int, vt<int>, greater<int>>
using namespace std;
using namespace __gnu_pbds;
lli tmod(lli x, lli y)
{
    return (x % y + y) % y;
}
template <typename T>
void DEBUG_ARR(vt<T> a)
{
    f(i, 0, a.size()) cout << a[i] << " ";
    cout << "\n";
}
lli power(lli x, lli y) 
{
    lli res = 1;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x)%mod; 
        y = y>>1; 
        x = (x*x)%mod;
    }
    if(res<0)res+=mod;
    return res; 
}
bool ok(lli q,ld m[],lli n,lli k){
    __int128_t check=0;
    f(i,0,n){
        ld x=q*m[i]*(i+1);
        check+=ceil(x);
        if(check>=k)return 0; 
    }
    return 1;
}
int main()
{   
    fastio;
    lli n;
    cin>>n;
    ld m[n];
    f(i,0,n)cin>>m[i];
    sort(m ,m +n, greater<ld>());
    lli k;cin>>k;
    lli val=(n*(n+1))/2;
    lli l=0,r=k/val+100;
    while(l<r){
        lli mid=(l+r)/2;
        if(ok(mid,m,n,k)){
            l = mid;
        }
        else r=mid-1;
    }
    cout<<l<<"\n";
    return 0;
}