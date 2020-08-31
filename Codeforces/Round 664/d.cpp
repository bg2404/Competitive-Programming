#include<bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, d, m;
    cin >> n >> d >> m;
    vector<long long> a(n), l, g;
    for(long long &i: a) {
        cin >> i;
        if(i > m) {
            g.push_back(i);
        } else {
            l.push_back(i);
        }
    }
    sort(l.begin(), l.end(), greater<long long>());
    sort(g.begin(), g.end(), greater<long long>());

    for(int i = 1; i < l.size(); ++i) {
        l[i] = l[i] + l[i-1];
    }
    for(int i = 1; i < g.size(); ++i) {
        g[i] = g[i] + g[i-1];
    }
    // cout << g.size() << ' ' << l.size() << '\n';
    long long ans = 0;
    {
        if(l.size() > 0) {
            ans = l.back();
            int tn = n - l.size();
            tn = tn / (d+1) + (tn % (d+1) != 0);
            if(tn > 0 && tn <= g.size()) {
                ans += g[tn-1];
            }
        }
    }
    long long temp = 0;
    for(int i = ((int)l.size()) - 1; i > 0; --i) {
        temp = l[i-1];
        int rn = n - i;
        rn = rn / (d+1) + (rn % (d+1) != 0);
        if(rn > 0 && rn <= g.size()) {
            temp += g[rn-1];
            ans = max(ans, temp);
        }
    }
    {
        long long temp = 0;
        int rn = n;
        rn = rn / (d+1) + (rn % (d+1) != 0);
        if(rn > 0 && rn <= g.size()) {
            temp += g[rn-1];
        }
        ans = max(ans, temp);
    }
    cout << ans << '\n';
    return 0;
}