#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main() {
    int n, k;
    cin >> n >> k;
    int input, odd = 0;
    for(int i =0; i < 1002; ++i) {
        a[i] = 0;
    }
    for(int i = 0; i < n; ++i) {
        cin >> input;
        a[input]++;
    }
    int cnt = 0;
    for(int i = 1; i <= k; ++i) {
        if(a[i] % 2) {
            odd++;
            cnt += a[i] - 1;
        } else {
            cnt += a[i];
        }
    }

    if(odd % 2) {
        odd++;
    }

    cnt += odd / 2;

    cout << cnt << '\n';

    return 0;
}