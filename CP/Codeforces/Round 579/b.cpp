#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int a[4*n];
        for(int i = 0; i < 4*n; ++i) {
            cin >> a[i];
        }

        sort(a, a + 4*n);

        long long prod = a[0] * a[4*n-1];
        bool ans = true;
        for(int i = 0; i < 2*n; i = i + 2) {
            if(a[i] == a[i+1] && a[4*n-i-1] == a[4*n-i-2]) {
                if(prod != a[i]*a[4*n-i-1]) {
                    ans = false;
                    break;
                }
            } else {
                ans = false;
                break;      
            }
        }

        if(ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}