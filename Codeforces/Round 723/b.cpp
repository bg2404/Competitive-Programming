#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long max_digits(long long x) {
    long long ans = 0;
    while (ans <= x) {
        ans = ans * 10 + 1;
    }
    ans /= 10;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        int rem = x % 11;
        if (x >= rem * 111) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}