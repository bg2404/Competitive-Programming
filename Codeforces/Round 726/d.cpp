#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    os << "[ ";
    for (T e : v) {
        os << e << " ";
    }
    os << ']';
    return os;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int f = 0;
        while (n % 2 == 0) {
            n /= 2;
            ++f;
        }
        if (f == 0) {
            cout << "Bob\n";
        } else if (n > 1) {
            cout << "Alice\n";
        } else if (f & 1) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
    return 0;
}