#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int32_t main() {
    int n, l = 0, r = 0;
    char c;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> c;
        if(c == 'L') ++l;
        else ++r;
    }

    cout << l + r + 1 << '\n';

    return 0;
}