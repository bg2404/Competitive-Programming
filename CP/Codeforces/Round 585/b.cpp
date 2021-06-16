#include<bits/stdc++.h>

using namespace std;

long long a[200010];
long long neg[200010];

int main() {
    long long n;
    cin >> n;
    long long even = 1, odd = 0;
    for(long long i = 1; i <= n; ++i) {
        cin >> a[i];
        neg[i] = neg[i-1] + (a[i] < 0);
        (neg[i]%2) ? odd++: even++;
    }

    long long num_pos = even*(even-1)/2 + odd*(odd-1)/2;
    long long num_neg = odd*even;

    cout << num_neg << ' ' << num_pos << '\n';

    return 0;
}