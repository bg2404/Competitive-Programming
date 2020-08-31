#include<bits/stdc++.h>

using namespace std;

struct LINE {
    int a, b, c;
};
void solve1(int n, int c, int k) {
    vector<LINE> lines;
    for(int i = 0; i < n; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        lines.push_back({a, b, c-1});
    }
    vector<int> v(c);
    for(int &i: v) {
        scanf("%d", &i);
    }
    int ans = 1000000000;
    int N = 1 << n;
    for(int i = 0; i < N; ++i) {
        int tans = 0;
        int temp = 1;
        int tcost = 0;
        for(int j = 0; j < n; ++j) {
            if((temp & i) == 0) {
                tcost += v[lines[j].c];
            }
            temp <<= 1;
        }
        if(tcost > k) {
            continue;
        } 
        for(int x = 0; x < n; ++x) {
            for(int y = x+1; y < n; ++y) {
                for(int z = y+1; z < n; ++z) {
                    if((i & (1<<x)) && (i & (1<<y)) && (i & (1<<z)) && (lines[x].c == lines[y].c) && (lines[y].c == lines[z].c) && (lines[x].a != lines[y].a) && (lines[y].a != lines[z].a) && lines[z].a != lines[x].a) {
                        ++tans;
                    }
                }
            }
        }
        ans = min(tans, ans);
    }
    printf("%d\n", ans);
}

vector<vector<long long> > dp; 

void solve2(int n, int c, int k) {
    vector<LINE> lines;
    vector<int> cnt(c+1);
    vector<vector<int> > cnts(c+1, vector<int> (n, 0)), sums2(c+1, vector<int> (n+1, 0));
    for(int i = 0; i < n; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        lines.push_back({a, b, c});
    }
    sort(lines.begin(), lines.end(), [](LINE &a, LINE &b) { return a.a < b.a; });
    vector<int> prev(c+1, -1), num(c+1, -1);
    for(LINE l: lines) {
        if(l.a == prev[l.c]) {
            l.a = num[l.c];
        } else {
            prev[l.c] = l.a;
            l.a = ++num[l.c];
        }
        ++cnt[l.c];
        ++cnts[l.c][l.a];
    }
    vector<int> v(c+1);
    for(int i = 1; i <= c; ++i) {
        cin >> v[i];
    }
    long long ans = 0;
    vector<int> nums(c+1, 0);
    for(int i = 0; i <= c; ++i) {
        int num = 0;
        if(cnt[i] > 2) {
            long long sum1 = 0;
            for(int j = 0; j < n; ++j) {
                if(cnts[i][j] == 0) {
                    break;
                }
                sum1 += cnts[i][j];
                ++num;
            }
            long long temp[num], sum2 = 0;
            for(int j = 0; j < num; ++j) {
                temp[j] = cnts[i][j]*(sum1 - cnts[i][j]);
                sum2 += temp[j];
            }
            int suf = cnts[i][num-1];
            for(int j = num-2; j >= 0; --j) {
                sums2[i][j] = sums2[i][j+1] + suf*cnts[i][j];
                suf += cnts[i][j];
            }
            sum2 /= 2;
            long long sum3 = 0;
            for(int j = 0; j < num; ++j) {
                sum3 += cnts[i][j]*(sum2 - temp[j]);
            }
            sum3 /= 3;
            ans += sum3;
        }
        nums[i] = num;
        sort(cnts[i].begin(), cnts[i].begin() + num);
        for(int j = 1; j < num; ++j) {
            cnts[i][j] = cnts[i][j-1] + cnts[i][j];
        }
    }
    dp.assign(c+1, vector<long long>(k+1, INT_MIN));
    dp[0][0] = 0;
    for(int i = 0; i < c; ++i) {
        for(int j = 0; j <= k; ++j) {
            if(dp[i][j] >= 0) {
                int c = 0;
                long long sum = 0;
                int idx = 0;
                while(idx + 2 < nums[i+1] && v[i+1]*c + j <= k) {
                    dp[i+1][j + v[i+1]*c] = max(dp[i+1][j+v[i+1]*c], dp[i][j] + sum);
                    ++c;
                    if(c > cnts[i+1][idx]) {
                        ++idx;
                    }
                    sum += sums2[i+1][idx+1];
                }
            }
        }
    }
    
    long long remove = 0;
    for(int i = 0; i <= k; ++i) {
        remove = max(remove, dp[c][i]);
    }
    ans -= remove;
    
    printf("%lld\n", ans);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, c, k;
        scanf("%d %d %d", &n, &c, &k);
        solve2(n, c, k);
    }
    return 0;
}