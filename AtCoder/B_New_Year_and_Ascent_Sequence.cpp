#include<bits/stdc++.h>
 
using namespace std;
 
int32_t main() {
    int n, m;
    cin >> n >> m;
    string s[n], t[m];
    for(int i = 1; i < n; ++i) {
        cin >> s[i];
    }
    cin >> s[0];
    for(int i = 1; i < m; ++i) {
        cin >> t[i];
    }
    cin >> t[0];
    int q, y;
    cin >> q;
    while(q--) {
        cin >> y;
        string a = s[y%n];
        string b = t[y%m];
        cout << a << b << '\n';
    }
    return 0;
}