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
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.size(), i;
        for(i = 0; i < n; ++i) {
            if(!(b[i] == c[i] || c[i] == a[i])) {
                break;
            }
        }
        if(i == n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}