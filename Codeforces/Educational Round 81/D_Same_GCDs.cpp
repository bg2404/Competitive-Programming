#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
}

vector<int> getFactors(int x) {
    vector<int> ans;
    if(!(x & 1)){
        ans.push_back(2);
        while(!(x & 1)) {
            x = x >> 1;
        }
    }

    for(int i = 3; i*i <= x; i += 2) {
        if(x % i == 0) {
            ans.push_back(i);
            while(x % i == 0) {
                x /= i;
            }
        }
    }

    if(x > 1) {
        ans.push_back(x);
    }
    return ans;
}


int countNum(vector<int> a, int m, int n) 
{ 
    int odd = 0, even = 0; 
    int counter, i, j, p = 1; 
    int pow_set_size = (1 << n); 
  
    // Run from counter 000..0 to 111..1 
    for (counter = 1; counter < pow_set_size;  
                                   counter++) 
    { 
        p = 1; 
        for (j = 0; j < n; j++)  
        { 
  
            // Check if jth bit in the  
            // counter is set If set  
            // then pront jth element from set  
            if (counter & (1 << j))  
            { 
                p *= a[j]; 
            } 
        } 
  
        // if set bits is odd, then add to 
        // the number of multiples 
        if (__builtin_popcount(counter) & 1) 
            odd += ( m / p ); 
        else
            even += ( m / p ); 
    } 
  
    return odd - even; 
} 

int32_t main() {
    int TestCase = 1;
    cin >> TestCase;
    while(TestCase--) {
        int a, m;
        cin >> a >> m;
        int d = gcd(a,m);
        // cout << "d = " << d << ' ';
        int p = a/d, q = m/d;
        int y = (m-1)/d;
        // int u = p/q, v = (p+y)/q;
        // printf("(%lld, %lld) ", p, q);        
        vector<int> factors = getFactors(q);
        // cout << factors.size() << ' ';
        // for(int i = 0; i <factors.size(); ++i) cout << factors[i] << ' ';
        // cout << '\n';
        int ans = countNum(factors, p + y, factors.size()) - countNum(factors, p-1, factors.size());
        
        cout << y + 1 - ans << '\n';
        
    }
    return 0;
}