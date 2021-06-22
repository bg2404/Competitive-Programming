#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, K;
        cin >> N >> K;
        string S;
        cin >> S;
        int ans = 0;
        for (int i = 0; i < N / 2; ++i) {
            if (S[i] != S[N - i - 1]) {
                ++ans;
            }
        }
        ans = abs(ans - K);
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}