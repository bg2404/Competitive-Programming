#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long 

using namespace std;

int32_t main() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    int h;
    int e[n];
    for(int i = 0; i < n; ++i) {
        cin >> h;
        h %= (a+b);
        // cout << h << ' ';
        if(h == 0) {
            h = a+b;
        }
        e[i] = ceil(((double)h)/a) - 1;
    }

    int ak = 0;
    sort(e, e+n);

    for(int i = 0; i < n; ++i) {
        if(k >= e[i]) {
            k -= e[i];
            ak++;
        } else {
            break;
        }
    }

    cout << ak << '\n';

    return 0;
}