#include<bits/stdc++.h>

using namespace std;
int dp[100010][2];
int ones[100010] = {0};
int zeroes[100010] = {0};
int dp_r[100010][2];

void init(string s) {
    zeroes[0] = 0;
    ones[s.size()] = (s[s.size()-1] == '1');
    for(int i = s.size()-2; i >= 0; --i) {
        if(s[i] == '1') {
            ones[i+1] = ones[i+2] + 1; 
        } else {
            ones[i+1] = ones[i+2];
        }
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp_r[s.size()+1][0] = 0;
    dp_r[s.size()+1][1] = 0;
    for(int i = s.size(); i > 0; --i) {
        if(s[i-1] == '0') {
            dp_r[i][0] = max(dp_r[i+1][0], dp_r[i+1][1]) + 1;
            dp_r[i][1] = dp_r[i+1][1];
        } else {
            dp_r[i][0] = dp_r[i+1][0];
            dp_r[i][1] = dp_r[i+1][1] + 1;
        }
    }
}

int main() {
    string s, t = "";
    cin >> s;
    ones[1] = s[0] - '0';
    zeroes[1] = 1 - ones[1];
    init(s);
    int n = max(dp_r[1][0], dp_r[1][1]);
    for(int i = 1; i <= s.size(); ++i) {
        if(s[i-1] == '0') {
            t = t + "0";
            dp[i][0] = dp[i-1][0] + 1;
            dp[i][1] = dp[i-1][1];
            zeroes[i] = zeroes[i-1] + 1;
        } else {
            s[i-1] = '0';
            int m = max(max(dp[i-1][0], dp[i-1][1]) + ones[i+1], zeroes[i-1] + 1 + max(dp_r[i+1][0], dp_r[i+1][1]));
            if(n == m) {
                t = t + "0";
                dp[i][0] = dp[i-1][0] + 1;
                dp[i][1] = dp[i-1][1];
                zeroes[i] = zeroes[i-1] + 1;
            } else {
                t = t + "1";
                dp[i][0] = dp[i-1][0];
                dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + 1;
                zeroes[i] = zeroes[i-1];
            }
            s[i-1] = '1';
        }
        s[i-1] = t[i-1];
    }
    cout << t << '\n';
    return 0;
}