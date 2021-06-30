#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, int k) {
    if(a.empty()) {
        return 1;
    }
    int l = 0, r = a.size() - 1, m, ans = r + 2;
    while(l <= r) {
        m = l + r >> 1;
        if(a[m] < k) {
            l = m + 1;
        } else {
            r = m - 1;
            ans = min(ans, m + 1);
        }
    }
    return ans;
}

int main() {
    int n, k, q;
    cin >> n >> k;
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
    }
    while(k--) {
        cin >> q;
        cout << solve(a, q) << '\n';
    }
    return 0;
}