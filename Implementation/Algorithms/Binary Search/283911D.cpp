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
    int n, k, l, r;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    cin >> k;
    while(k--) {
        cin >> l >> r;
        cout << solve(a, r + 1) - solve(a, l) << '\n';
    }
    return 0;
}