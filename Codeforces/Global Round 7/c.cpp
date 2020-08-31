#include<bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;

template<typename T>
void printVector(vector<T> v) {
    for(T x: v) {
        cout << x << ' ';
    }
    cout << '\n';
}

int32_t main() {
    int T = 1;
    // cin >> T;
    while(T--) {
        int n, k, sum = 0;
        cin >> n >> k;
        vector<int> pos, p(n);
        for(int i = 0; i < n; ++i) {
            cin >> p[i];
            if(p[i] > n-k) {
                pos.push_back(i);
                sum += p[i];
            }
        }

        int ans = 1;
        for(int i = 1; i < pos.size(); ++i) {
            ans  = (ans*(pos[i]-pos[i-1]))%MOD;
        }
        cout << sum << ' ' << ans << '\n';
    }
    return 0;
}