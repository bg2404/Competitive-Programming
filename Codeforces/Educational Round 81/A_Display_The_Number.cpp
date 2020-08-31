#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int32_t main() {
    int TestCase = 1;
    cin >> TestCase;
    while(TestCase--) {
        int n;
        cin >> n;
        int m = n & 1;
        int r = n / 2 - 1;
        if(m) {
            cout << 7;
        } else {
            cout << 1;
        }

        for(int i = 0; i < r; ++i) {
            cout << 1;
        }
        cout << '\n';

    }
    return 0;
}