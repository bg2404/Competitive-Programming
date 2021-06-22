#include <iostream>
#include <vector>

using namespace std;

void rec(vector<int> &a, vector<int> &d, int l, int r, int cd) {
    if (l <= r) {
        int idx = l;
        for (int i = idx + 1; i <= r; ++i) {
            if (a[idx] < a[i]) {
                idx = i;
            }
        }
        d[idx] = cd;
        rec(a, d, l, idx - 1, cd + 1);
        rec(a, d, idx + 1, r, cd + 1);
    }
}

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
        vector<int> d(n, -1);
        rec(a, d, 0, n - 1, 0);
        for (int i = 0; i < n; ++i) {
            cout << d[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}