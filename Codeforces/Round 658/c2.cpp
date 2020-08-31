#include<bits/stdc++.h>

using namespace std;

char oper(char c, bool comp) {
    int x = c - '0';
    if(comp) {
        x ^= 1;
    }
    return x+'0';
}

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> ans;
    int l = 0, r = n-1;
    bool comp = false;
    for(int i = n-1; i >= 0; --i) {
        // cout << l << ' ' << r << ' ' << comp << ' ' << oper(a[l],comp) << ' ' << oper(a[r],comp) <<'\n';
        if(oper(a[r], comp) == b[i]) {
            // cout << "#";
            if(l > r) {
                ++r;
            } else {
                --r;
            }
            continue;
        }
        if(oper(a[l], comp) == b[i]) {
            // cout << "$";
            ans.push_back(1);
        }
        comp ^= 1;
        swap(l, r);
        if(l > r) {
            ++r;
        } else {
            --r;
        }
        ans.push_back(i+1);
    }
    cout << ans.size() << ' ';
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}