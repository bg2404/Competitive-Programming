#include<bits/stdc++.h>

using namespace std;

void solve() {
    string t, s;
    cin >> t;
    for(int i = 0; i < t.size(); i += 2) {
        s.push_back(t[i]);
    }
    s.push_back(t[t.size()-1]);
    cout << s << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}