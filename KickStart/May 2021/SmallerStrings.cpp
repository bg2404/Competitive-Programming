#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main() {
    int totalNumberOfCases;
    cin >> totalNumberOfCases;
    for (int caseNumber = 1; caseNumber <= totalNumberOfCases; ++caseNumber) {
        long long n, k;
        cin >> n >> k;
        string s, t;
        cin >> s;
        t = s;
        long long ans = 0;
        int mid = ((n + 1) / 2) - 1;
        for (int i = 0; i <= mid; ++i) {
            ans *= k;
            ans += (s[i] - 'a');
            ans %= MOD;
            t[n - 1 - i] = t[i];
        }
        if (t < s) {
            ++ans;
            ans %= MOD;
        }
        cout << "Case #" << caseNumber << ": " << ans << endl;
    }
    return 0;
}