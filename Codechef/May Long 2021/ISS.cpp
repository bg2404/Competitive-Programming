#include <bits/stdc++.h>

using namespace std;

vector<int> totient(int n) {
    vector<int> p(n + 1);
    for (int i = 0; i <= n; ++i) {
        p[i] = i;
    }
    for (int i = 2; i <= n; ++i) {
        if (p[i] == i) {
            for (int j = i; j <= n; j += i) {
                p[j] -= p[j] / i;
            }
        }
    }
    return p;
}   

int main() {
    int T;
    scanf("%d", &T);
    int N = 4000001;
    vector<int> phi = totient(N);
    vector<int> dp(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            dp[j] += i * phi[j / i];
        }
    }
    while (T--) {
        int k;
        scanf("%d", &k);
        k = 4 * k + 1;
        printf("%d\n", (dp[k] + k - 2) / 2);
    }
    return 0;
}