#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    uint64_t a[n];
    uint64_t GCD;
    for(uint32_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    GCD = a[0];
    for(int i = 1; i < n; ++i) {
        GCD = __gcd(GCD, a[i]);
    }

    int num = 0;
    for(int i = 1; i <= sqrt(GCD); ++i) {
        if(GCD % i == 0) {
            if(GCD / i == i) {
                num++;
            } else {
                num += 2;
            }
        }
    }

    cout << num << '\n';

    return 0;
}