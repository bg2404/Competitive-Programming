//https://codeforces.com/contest/1324/problem/C

#include<bits/stdc++.h>
#define int long long

using namespace std;

template<typename T>
void printVector(vector<T> v) {
    for(auto u: v) {
        cout << u << ' ';
    }
    cout << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    // t = 1'
    while(t--) {
        string s;
        cin >> s;
        s = 'R' + s + 'R';
        // cout << s << ' ';
        int n = s.size();
        int ans = 0, l = n-1, d;
        for(int i = n-2; i >=0; --i) {
            if(s[i] == 'R') {
                d = l - i;
                l = i;
                ans = max(ans, d);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}