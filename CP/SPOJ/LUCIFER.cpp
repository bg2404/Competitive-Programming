#include<bits/stdc++.h>

using namespace std;

long long PRIME[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int dp[15][100];

long long F(long long K, long long D) {
    if(K == 0) {
        return D == 0;
    }

    if(dp[K][D] != -1) {
        return dp[K][D];
    }

    long long count = 0;

    for(long long i = 0; i < 10; ++i) {
        if(K & 1) {
            count += F(K-1, D+i);
        } else {
            count += F(K-1, D-i);
        }
    }

    dp[K][D] = count;

    return count;
}

long long solve(string num) {
    memset(dp, -1, sizeof(dp));
    long long count = 0;
    long long len = num.size();
    long long num_prime = sizeof(PRIME) / sizeof(PRIME[0]);

    long long total_diff = 0;

    for(int i = 0; i < len; ++i) {
            total_diff = -1*total_diff - (num[i] - '0');
    }

    for(long long i = 0; i < num_prime; ++i) {
        long long diff = PRIME[i];
        long long K = len;
        for(long long j = 0; j < len; ++j) {
            long long D = num[j] - '0';
            for(long long d = 0; d < D; ++d) {
                if(K & 1) {
                    count += F(K-1, diff+d);
                } else {
                    count += F(K-1, diff-d);
                }
            }
            if(K & 1) {
                diff += D;
            } else {
                diff -= D;
            }
            K--;
        }
        if(total_diff == PRIME[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    long long t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        long long i;
        istringstream(a) >> i;
        i--;
        ostringstream oss;
        if (oss << i) {
            a = oss.str();
        }
        cout << solve(b) - solve(a) << '\n';
    }
}