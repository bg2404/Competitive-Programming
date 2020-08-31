#include<bits/stdc++.h>
#define int long long

using namespace std;

template<typename T>
void printVec(vector<T> v) {
    for(auto u: v) {
        cout << u << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for(int i = 0, j = n-1; i < j; ++i, --j) {
            if(!(i & 1)) {
                swap(a[i], a[j]);
            }
        }
        for(int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}