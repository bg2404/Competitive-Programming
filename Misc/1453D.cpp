#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> ckt;
        long long k;
        cin >> k;
        if (k & 1) {
            cout << -1 << endl;
            continue;
        }
        int n = 1;
        int i = 0;
        while (k > 0) {
            if (k & 1) {
                ckt.push_back(i - 1);
                ckt.push_back(1);
                n += i;
            }
            k /= 2;
            ++i;
        }
        vector<int> ans(n, 0);
        ans[0] = 1;
        int prev = 0;
        for (int e : ckt) {
            prev += e;
            ans[prev] = 1;
        }
        ans.pop_back();
        cout << ans.size() << endl;
        for (int e : ans) {
            cout << e << ' ';
        }
        cout << endl;
    }
    return 0;
}