//https://cses.fi/problemset/task/1094
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) {
        cin >> x;
    }
    long long ans = 0;
    for(int i = 1; i < n; ++i) {
        if(a[i-1] > a[i]) {
            ans += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout << ans << '\n';
    return 0;
}