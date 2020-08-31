#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, d;
        cin >> n >> d;
        int a[n];
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        for(int i = 1; i < n; ++i) {
            if(a[i]*i <= d) {
                d -= a[i]*i;
                a[0] += a[i];
            } else {
                a[0] += d/i;
                d = 0;
                break;
            }
        }

        cout << a[0] << '\n';

    }
    return 0;
}