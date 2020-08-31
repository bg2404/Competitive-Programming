#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 

int32_t main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int a[n];
        int sum = 0;
        int neg = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            if(a[i] < 0 || (a[i] == 0 && (i == 0 || i == n-1))) ++neg;
        }

        int ans = max(maxSubArraySum(a + 1, n - 1), maxSubArraySum(a, n - 1));
        if(sum > ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
    return 0;
}