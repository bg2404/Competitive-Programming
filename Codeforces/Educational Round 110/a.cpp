#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s[4];
        cin >> s[0] >> s[1] >> s[2] >> s[3];
        if (min(s[0], s[1]) > max(s[2], s[3]) || min(s[2], s[3]) > max(s[0], s[1])) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}