//https://codeforces.com/contest/1324/problem/A
#include<bits/stdc++.h>
#define int long long

using namespace std;

template<typename T>
void printVector(vector<T> v) {
    for(auto u: v) {
        cout << u << ' ';
    }
    cout << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    // t = 1'
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int ctr = 0;
        for(int i = 0;i  <n; ++i) {
            cin >> a[i];
            a[i] = a[i] & 1;
            if(a[i]) {
                ctr++;
            }
        }
        if(ctr == 0 || ctr == n) {
            cout << "YES" << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}