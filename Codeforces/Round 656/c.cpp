#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        b = a;
        sort(b.begin(), b.end());
        map<int, int> rem;
        int cnt = 0, beg = 0, end = n - 1;
        for(int i = 0; i < n && beg <= end; ++i) {
            if(rem.count(b[i])) {
                --rem[b[i]];
                if(rem[b[i]] == 0) {
                    rem.erase(b[i]);
                }
                continue;
            }
            if(b[i] == a[beg]) {
                ++beg;
            } else if(b[i] == a[end]) {
                --end;
            } else {
                rem[a[beg++]]++;
                cnt = beg;
                --i;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}