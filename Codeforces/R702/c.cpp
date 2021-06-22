#include <iostream>
#include <vector>

using namespace std;

vector<long long> cube(10001);

bool binary_search(int a, long long x) {
    int l = 1, r = 10000, m;
    while (l <= r) {
        m = (l + r) >> 1;
        if (cube[a] + cube[m] == x) {
            return true;
        } else if (cube[a] + cube[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < 10001; i++) {
        cube[i] = ((long long)i * (i * i));
    }
    while (t--) {
        long long x;
        cin >> x;
        bool found = false;
        for (int i = 1; i < 10001; i++) {
            if (binary_search(i, x)) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}