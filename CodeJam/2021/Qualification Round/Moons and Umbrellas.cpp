#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int x, y;
        string s, mural;
        cin >> x >> y >> s;
        int n = s.length();
        mural = s[0];
        for (int i = 1; i < n; ++i) {
            if (mural.back() != s[i]) {
                mural.push_back(s[i]);
            }
        }
        n = mural.length();
        s = mural;

        int ans = 0;
        if (n > 1) {
            if (s[0] == '?') {
                if (s[1] == 'C') {
                    ans += min(y, 0);
                } else {
                    ans += min(x, 0);
                }
            } else if (s[0] == 'C') {
                if (s[1] == 'J') {
                    ans += x;
                }
            } else {
                if (s[1] == 'C') {
                    ans += y;
                }
            }
        }
        for (int i = 1; i + 1 < n; ++i) {
            if (s[i] == '?') {
                if (s[i - 1] == 'C') {
                    if (s[i + 1] == 'C') {
                        ans += min(x + y, 0);
                    } else {
                        ans += x;
                    }
                } else {
                    if (s[i + 1] == 'C') {
                        ans += y;
                    } else {
                        ans += min(x + y, 0);
                    }
                }
            } else if (s[i] == 'C') {
                if(s[i+1] == 'J') {
                    ans += x;
                }
            } else {
                if(s[i+1] == 'C') {
                    ans += y;
                }
            }
        }
        if (n > 1 && s[n - 1] == '?') {
            if (s[n - 2] == 'C') {
                ans += min(x, 0);
            } else {
                ans += min(y, 0);
            }
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
}