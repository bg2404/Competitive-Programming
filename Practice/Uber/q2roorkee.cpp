#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

vector<vector<int> > nCr;

int main() {
    nCr.assign(101, vector<int> (101, 0));
    nCr[0][0] = 1;
    for(int i = 1; i < 101; ++i) {
        nCr[i][0] = nCr[i][i] = 1;
        for(int j = 1; j < i; ++j) {
            nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
        }
    }
    string a, b, c;
    cin >> a >> b >> c;
    vector<int> cnta(26, 0), cntb(26, 0), cntc(26, 0);
    for(char i: a) {
        ++cnta[i-'a'];
    }
    for(char i: b) {
        ++cntb[i-'a'];
    }
    for(char i: c) {
        ++cntc[i-'a'];
    }
    long long a1 = 1, a2 = 1, a3 = 1, ans;
    for(int i = 0; i < 26; ++i) {
        a1 = (a1 * nCr[cnta[i] + cntb[i]][cntc[i]]) % MOD;
        a2 = (a2 * nCr[cnta[i]][cntc[i]]) % MOD;
        a3 = (a3 * nCr[cntb[i]][cntc[i]]) % MOD;
    }
    ans = ((a1 - a2 - a3) % MOD + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}