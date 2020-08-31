//https://www.codechef.com/COOK116A/problems/MYSARA
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ll long long
#define int long long
using namespace std;
// For ordered_set
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

unsigned int countSetBits(unsigned int n) 
{ 
    unsigned int count = 0; 
    while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 

int power(int x, unsigned int y, int p)  
{  
    int res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p  
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*1L*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*1LL*x) % p;  
    }  
    return res;  
}  

int32_t main(){
    // FILE_READ_IN
    test {
        int n;
        cin >> n;
        vector<int> B(n+1,0);
        loop(i, 0, n) {
            cin >> B[i];
        }
        int d = 0;
        bool pos = true;
        loop(i, 1, n) {
            d += countSetBits(B[i-1]);
            if((~B[i])&B[i-1]) {
                cout << 0 << '\n';
                pos = false;
                break;
            }
        }
        if(!pos) {
            continue;
        }
        int ans = power(2,d, MOD);
        cout << ans << '\n';        
    }
    return 0;
}