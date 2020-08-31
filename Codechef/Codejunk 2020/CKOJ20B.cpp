#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<unsigned long long> a;

long long solve(int x) {
    unsigned long long ret = 0;
    for(int i = 0; i < n; ++i) {
        long long c = 1;
        for(int j = 0; j < k; ++j) {
            c *= (x - a[i]);
        }
        ret += abs(c);
    }
    return ret;
}

int main() {
    cin >> n >> k;
    a = vector<unsigned long long> (n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    unsigned long long val = ULLONG_MAX, al, am, an;
    int ans = a[n-1] + 1;
    int l = a[0], r = a[n-1], m;
    while(l <= r) {
        m = l + r >> 1;
        al = solve(m-1);
        am = solve(m);
        an = solve(m+1);
        if(al > am && am < an) {
            if(val > am) {
                val = am;
                ans = m;
            } else if(val == am) {
                ans = min(ans, m);
            }
            r = m - 1;
        } else if(al >= am) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans << '\n';
}