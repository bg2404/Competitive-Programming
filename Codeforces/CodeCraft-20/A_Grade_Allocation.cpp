#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

template<typename T>
void printVec(vector<T> v) {
    int n = v.size();
    for(int i = 0; i < n; ++i) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

template<typename T>
void printArr(T arr[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc) {
        // cout << "Case #" << tc << ": \n";

        int n, m;
        cin >> n >> m;
        int a[n];
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int d = m - a[0];
        int s = 0;
        for(int i = 1; i < n; ++i) {
            s += a[i];
        } 

        d = min(d, s);

        cout << a[0] + d << '\n';
    }
    return 0;
}