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
        int c[3] = {0};
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++c[a[i] % 3];
        }
        int moves = 0;
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 3; ++i) {
                if (c[i] > n / 3) {
                    c[(i + 1) % 3] += c[i] - n / 3;
                    moves += c[i] - n / 3;
                    c[i] = n / 3;
                }
            }
        }
        cout << moves << endl;
    }
    return 0;
}