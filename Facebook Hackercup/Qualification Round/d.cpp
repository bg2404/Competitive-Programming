#include<bits/stdc++.h>

using namespace std;

multiset<long long> ms;
vector<long long> c;

void printAns(int t, long long ans) {
    cout << "Case #" << t << ": " << ans << '\n';
}

void solve(long T) {
    ms.clear();
    c.clear();
    int n, m;
    cin >> n >> m;
    c.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    if(m + 1 >= n) {
        printAns(T, 0);
        return;
    }
    for(int i = 1; i <= m; ++i) {
        if(c[i]) {
            ms.insert(c[i]);
        }
    }
    long long ans = 0;
    for(int i = m+1; i < n; ++i) {
        if(ms.empty()) {
            printAns(T, -1);
            return;
        }
        if(i+1 == n) {
            ans = *ms.begin();
            break;
        }
        if(c[i]) {
            c[i] += *ms.begin();
            ms.insert(c[i]);
        }
        if(c[i-m]) {
            ms.erase(ms.lower_bound(c[i-m]));
        }
    }
    cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    freopen("d.txt", "r", stdin);
    freopen("dout.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        solve(i);
    }
}
