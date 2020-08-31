#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n*2), ans;
        ans.reserve(n);
        set<int> s;
        for(int i = 0; i < n*2; ++i) {
            cin >> a[i];
            if(s.count(a[i]) == 0) {
                ans.push_back(a[i]);
                s.insert(a[i]);
            }
        }
        for(auto x: ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}