#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int i;
    for (i = 1; i < n; ++i) {
        if (s[0] < s[i]) {
            s = s.substr(0, i);
            break;
        } else if (s[0] == s[i]) {
            int p = 0, q = i;
            while (q < n && s[p] == s[q]) {
                ++p;
                ++q;
            }
            if (q < n) {
                if (s[p] < s[q]) {
                    s = s.substr(0, i);
                    break;
                } else {
                    i = q;
                }
            } else {
                s = s.substr(0, i);
                break;
            }
        }
    }
    while ((int)s.size() < k) {
        s = s + s;
    }
    while ((int)s.size() > k) {
        s.pop_back();
    }
    cout << s << '\n';
    return 0;
}