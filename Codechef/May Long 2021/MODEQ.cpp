#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    vector<vector<int> > factors(500000);
    for (int i = 1; i <= 500000; ++i) {
        for (int j = i; j <= 500000; j += i) {
            factors[j].push_back(i);
        }
    }
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> count(M + 1, 0);
        long long ans = 0;
        if (N > M) {
            ans = ans + ((long long)N * (N - 1)) / 2 - ((long long)M * (M - 1)) / 2;
            N = M;
        }
        for (int b = N; b > 0; --b) {
            int j = M - M % b;
            ans += (lower_bound(factors[j].begin(), factors[j].end(), b) - factors[j].begin());
        }
        cout << ans << endl;
    }
    return 0;
}