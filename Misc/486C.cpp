#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    string s;
    cin >> s;
    if(p + p > n + 1) {
        p = n - p + 1;
    }

    vector<int> a(n, 0);
    int ans = 0;
    for(int i = 0, j = n-1; i < j; ++i, --j) {
        if(s[i] != s[j]) {
            int x = s[i] - 'a';
            int y = s[j] - 'a';
            a[i] = a[j] = min((x - y + 26) % 26, (y - x + 26) % 26);
            ans += a[i];
        }
    }
    int beg = -1, end = -1;
    for(int i = 1; i <= n; ++i) {
        if(a[i-1]) {
            beg = i;
            break;
        }
    }
    for(int i = n/2; i > 0; --i) {
        if(a[i-1]) {
            end = i;
            break;
        }
    }
    if(beg == -1) {
        ans = 0;
    } else {
        ans += min(abs(p - beg), abs(p - end)) + abs(beg - end);
    }
    cout << ans << '\n';
    return 0;
}