#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

template<typename T>
void printVec(vector<T> a) {
    int n = a.size();
    for(int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

template<typename T>
void printArr(T a[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int32_t main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        if(m == 0) {
            cout << 0 << '\n';
            continue;
        }
        if(m == n) {
            cout << m*(m+1)/2 << '\n';
            continue;
        }
        int o = n - m, ans;
        int k = o/(m+1);
        // cout << k << ' ';
        // ans = m(2*(n-k)+(m-1)*(k+1))/2;
        ans = (k+1)*((m*(2*(n-k) - (m-1)*(k+1)))/2);
        cout << ans << '\n';
    }
    return 0;
}