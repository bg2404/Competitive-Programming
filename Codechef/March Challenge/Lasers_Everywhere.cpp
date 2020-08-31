#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#pragma GCC optimize ("-O3")
#define mod2 998244353
#define MAXN 1000000000
#define v32 vector<int>
#define v64 vector<lli>
#define v1024 vector <vector <int>>
#define v4096 vector <vector <lli>>
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
#define fd(x, y, z) for (lli x = y; x > z; x--)
#define lb lower_bound
#define ld long double
#define m64 map<lli,lli>
#define m32 map<int,int>
#define m64it map<lli,lli>::iterator
#define m32it map<int,int>::iterator
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ist insert
#define endl "\n"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define p_q priority_queue 
#define min_p_q priority_queue <int,vt <int>,greater <int>>
using namespace std;
using namespace __gnu_pbds; 
template <typename T> 
void DEBUG_ARR(vt<T> a,char c)
{
	f(i,0,a.size())cout<<a[i]<<c;
	cout<<"\n";
}

lli tmod(lli x,lli m){return (x%m+m)%m;}//USE AT YOUR OWN RISK
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
    if(res<0)
       res+=mod; 
    return res; 
}
// lli fact[2000009];
// lli ncr(lli n,lli r){
//     lli ans=fact[n];
//     if(r>n)return 0;
//     ans=(ans*power(fact[n-r],mod-2))%mod;
//     ans=(ans*power(fact[r],mod-2))%mod;
//     return ans;
// }
class LAZY //currently set to set a given range by a value
{
   public:
   struct node
   {
    int l,r,lazy=0;lli lazyval=0;
    lli sum=0;
   };	
   vt <node> st;v32 h;
   LAZY(v32 a)
   { 
   	  h=a;
   	  st.resize(4*h.size());
   	  cst(0,h.size()-1);
   }	
   void cst(int l,int r,int k=0)
   {
    st[k].l=l,st[k].r=r;
    if(l==r)
        { 
          st[k].sum=h[l];   
          return;
        }
    cst(l,(l+r)/2,2*k+1);
    cst((l+r)/2+1,r,2*k+2);
    st[k].sum=st[2*k+1].sum+st[2*k+2].sum;    
   }
   void shift(int k)
   {
   st[k].sum=(st[k].r-st[k].l+1)*st[k].lazyval;
   if(st[k].l!=st[k].r){
      st[2*k+1].lazyval=st[k].lazyval;
      st[2*k+2].lazyval=st[k].lazyval;
      st[2*k+1].lazy=st[2*k+2].lazy=1;
   }
   st[k].lazyval=0;
   st[k].lazy=0;      
   }
   lli query(int l,int r,int k=0)
   {
	  if(st[k].lazy) shift(k);
    int ll=st[k].l,rr=st[k].r;
    if(ll>r || rr<l)return 0;
    if(ll>=l && rr<=r)
    return st[k].sum;
    return query(l,r,2*k+1)+query(l,r,2*k+2);     
   }
   void update(int l,int r,lli x,int k=0)
   {
   int ll=st[k].l,rr=st[k].r;
   if(ll>r || rr<l)return ;
   if(ll>=l && rr<=r){
     st[k].lazyval=x;
     st[k].lazy=1;      
     return;
    }
    if(st[k].lazy) shift(k);
    if(ll==rr) return;
    update(l,r,x,2*k+1);
    update(l,r,x,2*k+2);
    if(st[2*k+1].lazy)  shift(2*k+1);
    if(st[2*k+2].lazy)  shift(2*k+2);
    st[k].sum=st[2*k+1].sum+st[2*k+2].sum;           
   }
   int lower_bound(int l,int r,int val)
   {
    while(l!=r)
    {
      int mid=(l+r)/2;
      if(query(mid,mid)>=val)
        r=mid;
      else 
        {l=mid+1;
         if(mid+1<h.size())  
             if(query(mid+1,mid+1)>val)
             {
              l=mid;
              break;
             }
        }
    }
    return l;
   }
};
int main() 
{ 
    fastio;
    // fact[0]=1;
    // f(i,1,2000009)fact[i]=(fact[i-1]*i)%mod;
    int t;
    cin>>t;
    // t=1;
    while(t--){
       int n,q;cin>>n>>q;
       v32 a(n);f(i,0,n)cin>>a[i];
       vt <pair<pair<int,int>,int>> segments;
       f(i,0,n-1) segments.push_back({{min(a[i],a[i+1]),max(a[i],a[i+1])},i});
       v32 forST(n-1,0);
       LAZY ST(forST);
       vt <pair<pair<pair<int,int>,int>,int>> queries;
       f(i,0,q){
           int x1,x2,y;cin>>x1>>x2>>y;
           queries.push_back({{{y,x1},x2},i});
       } 
       sort(queries.begin(),queries.end());
       sort(segments.begin(),segments.end());
       int pos=0;
       set <pair<int,int>> residing_set;
       int ans[q];
       int prevy=-1;
       f(i,0,q){
           int x1,x2,y;
           x1=queries[i].first.first.second;
           x2=queries[i].first.second;
           y=queries[i].first.first.first;
           x1--,x2--;
           int pos_for_ans=queries[i].second;
           if(prevy==y){
               ans[pos_for_ans]=ST.query(x1,x2-1);
               continue;
           }
           while(pos<n-1 && segments[pos].first.first<=y){
               if(segments[pos].first.second>=y){
                   residing_set.insert({segments[pos].first.second,segments[pos].second});
                   ST.update(segments[pos].second,segments[pos].second,1);
               }
               pos++;
           }
           while(residing_set.size() && residing_set.begin()->first<y){
               ST.update(residing_set.begin()->second,residing_set.begin()->second,0);
               residing_set.erase(residing_set.begin());
           } 
           ans[pos_for_ans]=ST.query(x1,x2-1);
           prevy=y;
        //    if(x1!=0 && a[x1]==y){
        //        ans[pos_for_ans]--;
        //    }
        //    if(a[x2]==y && x2!=n-1)ans[pos_for_ans]--;
        //    cout<<pos_for_ans<<" "<<residing_set.size()<<"\n";
       }
       f(i,0,q)cout<<ans[i]<<"\n";
    }
    return 0; 	
}