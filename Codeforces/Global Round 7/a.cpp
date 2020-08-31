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
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        if(n == 1) {
            cout << -1 << '\n';
            continue;
        }
        cout << 2;
        for(int i = 1; i < n; ++i) {
            cout << 9;
        }
        cout << '\n';
    }
    return 0;
}