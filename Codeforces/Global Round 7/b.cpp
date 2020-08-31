#include<bits/stdc++.h>

using namespace std;

template<typename T>
void printVector(vector<T> v) {
    for(T x: v) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n,0), b(n, 0);
        for(int  i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int m = 0;
        for(int i = 0; i < n; ++i) {
            a[i] = b[i] + m;
            m = max(m, a[i]);
        }
        printVector(a);
    }
    return 0;
}