#include<bits/stdc++.h>

using namespace std;

long long fac[500001];

long long power(long long x, long long y, long long p) 
{ 
    long long res = 1;      // Initialize result 

    x = x % p;  // Update x if it is more than or 
                // equal to p 

    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 

        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 

// Returns n^(-1) mod p 
long long modInverse(long long n, long long p) 
{ 
    return power(n, p-2, p); 
} 

// Returns nCr % p using Fermat's little 
// theorem. 
long long nCrModP(long long n, long long r, long long p) 
{ 
    // Base case 
    if (r==0) 
        return 1;     

    
    return (((fac[n] *modInverse(fac[r], p)) % p) * 
            modInverse(fac[n-r], p) % p) % p; 
} 

int main() {
    long long MOD = 998244353;
    long long n, k;
    cin >> n >> k;
    fac[0] = 1; 
    for (long long i=1 ; i<=n; ++i) 
        fac[i] = (fac[i-1]*i)%MOD; 
    if(k == 1) {
        cout << n << '\n';
        return 0;
    }
    if(n < k) {
        cout << 0 << '\n';
        return 0;
    }
    
    long long ans = 0;
    for(long long i = 1; i <= n; ++i) {
        if(n/i < k) {
            break;
        }
        // cout << n / i - 1 << ' ' << k - 1 << ' ';
        ans += nCrModP(n/i - 1, k-1, 998244353);
        ans %= MOD;
    }
    cout << ans << '\n';

}