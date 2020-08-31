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
v64 D[15][11];
int main()
{   
    fastio;
    int n;
    cin>>n;
    lli a[n];f(i,0,n)cin>>a[i];
    f(i,1,min(11,n)){
        f(j,0,i){
            for(int counter=0;counter*i+j<n;counter++){
                D[i][j].push_back(a[counter*i+j]);
            }
        }
    }
    f(i,0,min(11,n)){
        f(j,0,i){
            f(k,1,D[i][j].size())
                D[i][j][k]+=D[i][j][k-1];
        }
    }
    int q;cin>>q;
    f(i,0,q){
        lli l,r,d;
        cin>>l>>r>>d;
        l--,r--;
        int k=(r-((r-l)/d)*d)/d-1;
        cout<<D[d][r%d][r/d]-(k>-1)*D[d][r%d][k]<<"\n";
    }
    return 0;
}