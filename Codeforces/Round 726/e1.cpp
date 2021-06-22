#include <bits/stdc++.h>

using namespace std;

string get(string s, int k) {
    while ((int)s.size() < k) {
        s = s + s;
    }
    while ((int)s.size() > k) {
        s.pop_back();
    }
    return s;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string ans(k, s.front());
    for (int i = 2; i <= n; ++i) {
        ans = min(ans, get(s.substr(0, i), k));
    }
    cout << ans << endl;
}