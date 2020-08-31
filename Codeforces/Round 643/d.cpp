#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    if(s < 2*n) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for(int i = 1; i < n; ++i) {
            cout << 2 << ' ';
            s -= 2;
        }
        cout << s << '\n';
        cout << 1 << '\n';
    }
}