//https://cses.fi/problemset/task/1069
#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0, cnt = 0;
    char prev = 0;
    for(auto c: s) {
        if(c == prev) {
            ++cnt;
        } else {
            ans = max(ans, cnt);
            prev = c;
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    cout << ans << '\n';

    return 0;
}