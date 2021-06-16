#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    cout << "[ ";
    for (T e : v) {
        cout << e << ' ';
    }
    cout << ']';
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
        int k;
        cin >> k;
        int g = gcd(k, 100 - k);
        cout << 100 / g << endl;
    }
    return 0;
}