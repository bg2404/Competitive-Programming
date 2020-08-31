#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, x;
        cin >> n >> x;
        int a[n],ans = 1000000000;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] == x) {
                ans = 1;
            }
        }
        sort(a, a + n);
        int sum = x / a[n-1];
        int rem = x%a[n-1];
        
        if(rem > 0) {
            if(sum == 0) ++sum;
            sum++;
        }
        sum = min(ans, sum);

        cout << sum << '\n';

    }
    return 0;
}