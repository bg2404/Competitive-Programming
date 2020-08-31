#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> wc(51, 0), w(n);
    for(int &i: w) {
        cin >> i;
        ++wc[i];
    }
    int ans = 0;
    for(int i = 2; i < 101; ++i) {
        vector<int> cnt(51, 0);
        int tans = 0;
        for(int j = 0; j < n; ++j) {
            int a = w[j], b = i - w[j];
            if(b < 51 && b > 0 && cnt[a] < wc[a] && cnt[b] < wc[b]) {
                if(a != b) {
                    ++cnt[a]; ++cnt[b];
                    ++tans;
                } else {
                    if(cnt[a] + 1 < wc[a]) {
                        cnt[a] += 2;
                        ++tans;
                    }
                }
            }
        }
        ans = max(ans, tans);
    }
    cout << ans << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}