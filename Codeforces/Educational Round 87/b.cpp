#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int ans = s.size() + 10, l[4] = {-1, -1, -1, -1};
    for(int i = 0; i < s.size(); ++i) {
        l[s[i]-'0'] = i;
        if(l[1] == -1 || l[2] == -1 || l[3] == -1) {
            continue;
        }
        ans = min(ans, 1 + max(abs(l[1]-l[2]), max(abs(l[2]-l[3]), abs(l[3]-l[1]))));
    }
    if(ans > s.size()) {
        ans = 0;
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}