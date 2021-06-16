#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> &v) {
    os << "[ ";
    for(T e: v) {
        os << e << ' ';
    }
    os << ']';
    return os;
}

int value(char ch) {
    return 26 - (ch - 'a');
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int> > dp(n, vector<int>(n, 0));
    dp[0][0] = value(s[0]);
    for (int i = 1; i < n; ++i) {
        dp[i][i] = value(s[i]);
        dp[i - 1][i] = max(value(s[i - 1]), value(s[i]));
    }
    for (int j = 2; j < n; ++j) {
        for (int i = 0; i + j < n; ++i) {
            dp[i][i + j] = max(value(s[i]) + min(dp[i + 1][i + j - 1], dp[i + 2][i + j]),
                               value(s[i+j]) + min(dp[i + 1][i + j - 1], dp[i][i + j - 2]));
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}