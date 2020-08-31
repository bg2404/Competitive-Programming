#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int32_t main() {
    int T;
    cin >> T;
    while(T--) {
        int n, p;
        cin >> n >> p;
        int d[n];
        vector<int> coins(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> d[i];
        }

        int sum = 0;

        for(int i = n-1; i >= 0 && sum < p; --i) {
            int rem = p - sum;
            if(rem % d[i] == 0) {
                coins[i] = rem/d[i] - 1;
            } else {
                coins[i] = rem/d[i] + 1;
            }
            sum += coins[i]*d[i];
        }

        if(sum < p) {
            cout << "NO\n";
        } else {
            cout << "YES ";
            for(int i = 0; i < n; ++i) {
                cout << coins[i] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}