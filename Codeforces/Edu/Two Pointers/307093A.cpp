#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long s;
    cin >> n >> s;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long sum = a[0];
    int ans = 0, i, j;
    for (i = 0, j = 1; j <= n;) {
        if (sum <= s) {
            ans = max(ans, j - i);
            sum += a[j++];
        } else {
            sum -= a[i++];
        }
    }
    cout << ans << '\n';
    return 0;
}