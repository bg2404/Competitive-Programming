#include<bits/stdc++.h>

using namespace std;

int64_t MOD = 1000000007;
int64_t POWER[100010] = {1};
int64_t DP[100010][10];
int64_t F(int64_t K, int64_t D) {
    if(D < 0) {
        return 0;
    }
    if(K == 1) {
        return D;
    }

    if(DP[K][D]) {
        return DP[K][D];
    }

    int64_t count = 0;
    if(K < 3) {
        for(int64_t i = 0; i < 10 ; ++i) {
            count = ( count + F(K-1, i) ) % MOD;
        }
    } else {
        count = (count + F(K-1,9)) % MOD;
        cout << "F(" << K-1 << ", " << 9 << ") = " << count << '\n';
    }
    count = (count * (D+1)) % MOD;
    for(int64_t d = 0; d <= D; ++d) {
        count = (count - (d * ((POWER[K-2]*POWER[K-2])%MOD)) % MOD);
        count = (count + (d * ((POWER[K-1]*POWER[K-1])%MOD)) % MOD);
    }
    DP[K][D] = count;
    return count;    
}

int64_t solve(string s, int n) {
    int len = n;
    int64_t sum = 0;
    int64_t num_till_now = 0;
    int D_prev = 0;
    for(int i = 0; i < len; ++i) {
        int D = s[i] - '0';
        if(i < len-1) {
            sum = ((sum+F(len - i, D - 1))%MOD + num_till_now*D*((POWER[len-i]*POWER[len-i-1])%MOD)) % MOD ;
        } else {
            sum = ((sum + D*(D+1)/2)%MOD + num_till_now*10*(D+1))%MOD;
        }
        if(D == D_prev) {
            num_till_now = (num_till_now*10)%MOD;
        } else {
            num_till_now = (num_till_now*10+D)%MOD;
        }

        if(i > 0) {
            if(D_prev < D) {
                sum = (sum-(D_prev*POWER[len-i-1]*POWER[len-i-1])%MOD) % MOD;
            } else if(i == len-1 && D_prev == D) {
                sum = (sum - D) % MOD;
            }
        }
        D_prev = D;
    }
    return sum;
}

int main() {
    int64_t T;
    cin >> T;
    while(T--) {
        int64_t N_L, N_R;
        string L, R;
        cin >> N_L >> L >> N_R >> R;
        for(int i = N_L - 1; i >= 0; --i) {
            if(L[i] != '0') {
                L[i] -= 1;
                break;
            }
            L[i] = '9';
        }
        for(int64_t i = 0; i < N_R; ++i) {
            POWER[i+1] = (POWER[i]*10) % MOD;
        }
        int64_t solve_N_R = solve(R, N_R);
        int64_t solve_N_L = solve(L, N_L);
        cout << "\n\n" << solve_N_R  << ' '<< solve_N_L << ' ' << solve_N_R - solve_N_L << '\n';
    }
    return 0;
}