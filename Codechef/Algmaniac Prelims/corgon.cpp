#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n], xor_arr[n-k+1];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int t_xor = 0;
    for(int i = 0; i < k; ++i) {
        t_xor ^= a[i];
    }

    a[0] = t_xor;

    for(int i = 1; i + k < n; ++i) {
        t_xor = t_xor ^ a[i-1] ^ a[i+k-1];
        a[i] = t_xor;
    }

    for(int i = 0)
    return 0;
}