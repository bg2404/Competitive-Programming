#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long a[n], d[n-1];
    for(long long i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);
    for(long long i = 1; i < n; ++i) {
        d[i-1] = a[i] - a[i-1];
    }

    long long mid = n / 2;
    long long median = a[mid];
    long long k_left = k;
    long long i;
    for(i = mid; i < n - 1; ++i) {
        long long num = i - mid + 1;
        if(k_left >= num) {
            if(d[i]*num <= k_left) {
                median += d[i];
                k_left -= d[i]*num;
            } else {
                long long x = k_left / num;
                median += x;
                k_left -= x*num;
                break;
            }
        } else {
            break;
        }
    }
    if(k_left > mid && i == n-1) {
        median += k_left / (mid + 1);
    }
    cout << median << '\n';
    return 0;
}