#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            int x = min(a[i - 1], a[i]);
            int y = max(a[i - 1], a[i]);
            int lcnt = 0;
            while (x * 2 < y) {
                ++lcnt;
                x <<= 1;
            }
            cnt += lcnt;
        }
        cout << cnt << endl;
    }
    return 0;
}