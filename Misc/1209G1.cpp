#include<bits/stdc++.h>

using namespace std;

vector<int> be(200001, -1);
vector<int> en(200001, -1);
vector<int> cnt(200001, 0);

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);

    for(int i = 0; i < n; ++i)  {
        cin >> a[i];
        if(be[a[i]] == -1) {
            be[a[i]] = en[a[i]] = i;
        } else {
            en[a[i]] = i;
        }
        ++cnt[a[i]];
    }
    int ans = 0;
    int s = -1, e = -1, tans = 0, tmax = 0;
    for(int i = 0; i < n; ++i) {
        if(e < i) {
            s = be[a[i]];
            e = en[a[i]];
            ans += tans - tmax;
            tans = 0;
            tmax = 0;
        }
        if(be[a[i]] == i) {
            tans += cnt[a[i]];
            tmax = max(tmax, cnt[a[i]]);
        }
        e = max(e, en[a[i]]);
    }
    ans += tans - tmax;
    cout << ans << '\n';
    return 0;
}