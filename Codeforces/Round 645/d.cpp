#include<bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long n, x;
    cin >> n >> x;
    vector<unsigned long long> d(2*n+1), pre(2*n+1, 0), ps(2*n+1, 0);
    d[0] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> d[i];
        d[n+i] = d[i];
    }
    for(int i = 1; i <= 2*n; ++i) {
        pre[i] += pre[i-1] + d[i];
        ps[i] = ps[i-1] + (d[i]*(d[i]+1))/2;
    }
    unsigned long long ans = 0;
    for(int i = 2*n; i > n; --i) {
        auto itr = upper_bound(pre.begin(), pre.begin() + i + 1, pre[i] - x);
        unsigned int idx = --itr - pre.begin();
        unsigned long long tans = ps[i] - ps[idx];
        unsigned long long cnt = pre[i] - pre[idx] - x;
        tans -= (cnt*(cnt+1))/2;
        ans = max(ans, tans);
    }

    cout << ans << '\n';

    return 0;
}