#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int &i : a) {
            cin >> i;
        }
        for (int &i : b) {
            cin >> i;
        }

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += a[i] * (long long)b[i];
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}