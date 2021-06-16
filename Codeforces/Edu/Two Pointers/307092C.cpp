#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    long long ans = 0;
    int i, j;
    for (i = 0, j = 0; i < n;) {
        while (j < m && b[j] < a[i]) {
            ++j;
        }
        if (j < m && a[i] == b[j]) {
            int x = 0, y = 0, z = a[i];
            while (i < n && a[i] == z) {
                ++i;
                ++x;
            }
            while (j < m && b[j] == z) {
                ++j;
                ++y;
            }
            ans += (long long)x * y;
        } else {
            ++i;
        }
    }
    cout << ans << '\n';
    return 0;
}