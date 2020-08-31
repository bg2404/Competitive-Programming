#include<bits/stdc++.h>
#define epsilon 0.0000001
using namespace std;

bool maxPossible(vector<int> &a, int k, double l) {
    int ans = 0;
    for(int i: a) {
        ans += i / l;
    }
    return ans >= k;
}

double solve(vector<int> &a, int k) {
    double l = 0, r = 10000000, m, ans = 0;
    while(l + epsilon <= r) {
        m = (l + r) / 2;
        if(maxPossible(a, k, m)) {
            if(abs(ans - m) < epsilon) {
                return ans;
            }
            ans = max(ans, m);
            l = m + epsilon;
        } else {
            r = m;
        }
    }
    return ans;
}

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
    }
    cout << setprecision(10) << solve(a, k);
    return 0;
}