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
//build function
//supports update and query 
class merge_sort_tree
{
  public:
	struct node
    {
      int l,r;
      ordered_set mp;
    };
	v32 a;
    vt <node> st; 
	
    merge_sort_tree(v32 b){
        a=b;
        st.resize(4*a.size());
        build(0,a.size()-1);
    }
    void build(int l,int r,int k=0){
        st[k].l=l,st[k].r=r;
        if(l==r){
            st[k].mp.insert(a[l]);
            return;
        }
        f(i,l,r+1)st[k].mp.insert(a[i]);
        build(l,(l+r)/2,2*k+1);
        build((l+r)/2+1,r,2*k+2);
    }
    void update(int id,int orig,int val,int k=0){
        int l=st[k].l,r=st[k].r;
        if(id<l || id>r) return;
        if(l==id && id==r){
            st[k].mp.erase(orig);
            st[k].mp.insert(val);
            return;
        }
        st[k].mp.erase(orig);
        st[k].mp.insert(val);
        update(id,orig,val,2*k+1);
        update(id,orig,val,2*k+2);
    }
    int query(int l,int r,int upper,int k=0){
        if(l>r)return 0;
        int ll=st[k].l,rr=st[k].r;
        if(r<ll || rr<l) return 0;
        if(l<=ll && rr<=r){
            return st[k].mp.order_of_key(upper);
        }
        return query(l,r,upper,2*k+1)+query(l,r,upper,2*k+2);   
    }
};
struct bulb{
    int a,b,c;
    bool operator <(struct bulb &x){
        return b>x.b;
    }
};
bool comparator(bulb a,bulb b){
    return a.b<b.b;
}
bool comparator2(pair<bulb,int> a,pair<bulb,int> b){
    return a.first.a<b.first.a;
}
bool comparator3(pair<bulb,int> a,pair<bulb,int> b){
    return a.first.b<b.first.b;
}
int lower_bound_bulb(int l,int r,int b,vt<bulb > &bulbs){
    while(l<r){
        int mid=(l+r)>>1;
        if(bulbs[mid].b<=b){
            if(bulbs[mid+1].b>b)return mid;
            l=mid+1;
        }
        else r=mid;
    }
    return l;
}

int main() 
{ 
    fastio;
    // fact[0]=1;
    // f(i,1,2000009)fact[i]=(fact[i-1]*i)%mod;
    int t;
    // cin>>t;
    t=1;
    while(t--){
       int n,q;cin>>n>>q;
       vt <bulb> bulbs(n);f(i,0,n){
           cin>>bulbs[i].a>>bulbs[i].b>>bulbs[i].c;
       }
        int ans[q];
       vt<pair<bulb, int> > A_pair(n);
       sort(bulbs.begin(),bulbs.end(),comparator);
       vt <pair<bulb,int>> queries(q);
       f(i,0,q){
           queries[i].second=i;
           cin>>queries[i].first.a>>queries[i].first.b>>queries[i].first.c;
        } 

        f(i, 0 , q) {
            A_pair[i] = {bulbs[i], i};
        }
        sort(queries.rbegin(),queries.rend(),comparator2);  //error prone
        sort(A_pair.rbegin(), A_pair.rend(), comparator2);
        v32 forST(MAXN);
        merge_sort_tree ST(forST);
        int a_pos = 0;
        // f(i, 0 , q) {
        //     int x, y, z;
        //     x = queries[i].first.a;
        //     y = queries[i].first.b;
        //     z = queries[i].first.c;
        //     ++z;
        //     while(A_pair[a_pos].first.a >= x) {
        //         ST.update(A_pair[a_pos].second, MAXN, A_pair[a_pos].first.c);
        //         --a_pos;
        //     }

        //     int index = lower_bound_bulb(0, n-1, y,bulbs);
        //     // --index;

        //     ans[queries[i].second] = ST.query(0, index, z);

        // }

        f(i, 0, q) {
            cout << ans[i] << ' ';
        }
        cout << endl;

    }
    return 0; 	
}