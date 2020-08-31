#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > dpp, dpc;

int main() {
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    vector<int> a(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dpp = dpc = vector<vector<int> >(m+1, vector<int>(b+1, 0));
    dpp[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            for(int k = 0; k <= b; ++k) {
                dpc[j][k] = dpp[j][k];
                if(j > 0 && k >= a[i]) {
                    dpc[j][k] += dpc[j-1][k-a[i]];
                    dpc[j][k] %= mod;
                }
            }
        }
        dpp = dpc;
    }
    int ans = 0;
    for(int i = 0; i <= b; ++i) {
        ans += dpp[m][i];
        ans %= mod;
    }

    cout << ans << '\n';
    return 0;
}