//https://codeforces.com/contest/1324/problem/D

#include<bits/stdc++.h>
#define int long long

using namespace std;

template<typename T>
void printVector(vector<T> v) {
    for(auto u: v) {
        cout << u << ' ';
    }
    cout << '\n';
}

int32_t main() {
    int t;
    // cin >> t;
    t = 1;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i) {
            cin >> b[i];
            b[i] = a[i] - b[i];
        }
        sort(b.begin(), b.end());
        int ans = 0;
        for(int i = 0; i < n-1; ++i) {
            int index = upper_bound(b.begin(), b.end(), -b[i]) - b.begin();
            // cout << index << ' ';
            if(b[i] > 0) {
                ans += n - 1 - i;
            } else {
                ans += n - index;
            }
        }
        cout << ans << '\n';

    }
    return 0;
}