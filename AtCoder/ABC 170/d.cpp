#include<bits/stdc++.h>

using namespace std;

int s[1000001];
vector<int> a;

int main() {
    int n, x;
    cin >> n;
    int MAX = 0;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        MAX = max(MAX, x);
        ++s[x];
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(s[a[i]] == 0) continue;
        if(s[a[i]] == 1) ++ans;
        int cur = a[i];
        for(int j = cur; j <= MAX; j += cur) {
            s[j] = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}