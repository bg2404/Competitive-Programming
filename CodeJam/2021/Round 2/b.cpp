#include <bits/stdc++.h>

using namespace std;

int main() {
    int totalNumberOfCases;
    cin >> totalNumberOfCases;
    int MAX = 1000000;
    vector<int> dp(MAX + 1, 0);
    for (int i = 2; i <= MAX; ++i) {
        if (dp[i] == 0) {
            dp[i] = 1;
        }
        for (int k = (i + 1) * 2; k <= MAX; k += i + 1) {
            dp[k] = max(dp[k], dp[i] + 1);
        }
    }
    for (int caseNumber = 1; caseNumber <= totalNumberOfCases; ++caseNumber) {
        int n;
        cin >> n;
        int ans = 1;
        for (int i = 3; i * i <= n; ++i) {
            if (n % i == 0) {
                ans = max(ans, 1 + max(dp[n / i - 1], dp[i - 1]));
            }
        }
        cout << "Case #" << caseNumber << ": " << ans << endl;
    }
    return 0;
}