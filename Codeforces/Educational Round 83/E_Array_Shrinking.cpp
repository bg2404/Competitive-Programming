#include<bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int dp[n][n];
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; ++i) {
        for(int j = i; j >= 0; --j) {
            if(i == j) {
                dp[i][j] = a[i];
            } else {
                for(int k = j; k < i; ++k) {
                    if(dp[j][k] == dp[k+1][i] && dp[j][k] != -1) {
                        dp[j][i] = dp[j][k]+1;
                    }
                }
            }
        }
    }

    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < n; ++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ans[n];
    for(int i = 0; i < n; ++i) {
        ans[i] = i+1;
        for(int j = 0; j < i; ++j) {
            if(dp[j+1][i] > 0) {
                ans[i] = min(ans[i], 1 + ans[j]);
            }
        }
        if(dp[0][i] > 0) {
            ans[i] = 1;
        }
    }
    cout << ans[n-1] << '\n';
    
    return 0;
}