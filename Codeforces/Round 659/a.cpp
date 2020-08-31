#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
    }
    vector<string> s(n+1);
    s[0] = string(51, 'a');
    for(int i = 1; i <= n; ++i) {
        s[i] = s[i-1];
        s[i][a[i-1]]++;
        if(s[i][a[i-1]] > 'z') {
            s[i][a[i-1]] = 'a';
        }
    }
    for(string i: s) {
        cout << i << '\n';
    }
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}