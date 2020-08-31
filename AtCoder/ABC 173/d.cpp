#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    long long ans = a[n-1], j = n - 1;
    for(long long i = 2; i < n; ++i) {
        if(!(i & 1)) {
            --j;
        }
        ans += a[j];
    }
    cout << ans << '\n';
    return 0;
}