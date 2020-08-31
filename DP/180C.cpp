//https://codeforces.com/contest/180/problem/C

#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> u(n+1, 0), l(n+1,0);
    for(int i = 1; i <= n; ++i) {
        if(islower(s[i-1])) {
            u[i] = u[i-1] + 1;
            l[i] = l[i-1];
        } else {
            u[i] = u[i-1];
            l[i] = l[i-1] + 1;
        }
    }

    int ans = 1000000007;
    for(int i = 0; i <= n; ++i) {
        ans = min(ans, u[i] + l[n] - l[i]);
    }
    cout << ans << '\n';
    return 0;
}