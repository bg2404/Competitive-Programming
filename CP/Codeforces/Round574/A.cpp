#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main() {
    int n, k;
    cin >> n >> k;
    int input, odd;
    for(int i = 0; i < n; ++i) {
        cin >> input;
        a[input]++;
    }
    int count = 0;
    for(int i = 0; i < k; ++i) {
        if(a[i] % 2) {
            odd++;
            count += a[i] - 1;
        } else {
            count += a[i];
        }
    }

    if(odd % 2) {
        odd++;
    }

    count += odd / 2;

    cout << count << '\n';
    return 0;
}