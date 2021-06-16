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
        if (n < 3) {
            cout << 0 << '\n';
        } else {
            int m = -1, c = -1, x = -1;
            bool pos = true;
            for (int i = 1; i < n; ++i) {
                if (a[i] >= a[i - 1]) {
                    int temp = a[i] - a[i - 1];
                    if (c == -1 || c == temp) {
                        c = temp;
                    } else {
                        pos = false;
                        break;
                    }
                } else {
                    int temp = a[i - 1] - a[i];
                    if (x == -1 || x == temp) {
                        x = temp;
                    } else {
                        pos = false;
                        break;
                    }
                }
            }
            if (!pos) {
                cout << -1 << '\n';
            } else if (c == -1 || x == -1) {
                cout << 0 << '\n';
            } else {
                int m = x + c;
                for (int i = 0; i < n; ++i) {
                    if (a[i] >= m) {
                        pos = false;
                        break;
                    }
                }
                if (x == 0) {
                    pos = false;
                }
                if (pos) {
                    cout << m << ' ' << c << '\n';
                } else {
                    cout << -1 << '\n';
                }
            }
        }
    }
    return 0;
}