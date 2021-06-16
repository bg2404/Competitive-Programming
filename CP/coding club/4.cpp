#include<bits/stdc++.h>

using namespace std;

long long n, k, A, B;
vector<long long> a;

long long min(long long a, long long b) {
    if(a < b) {
        return a;
    }
    return b;
}

long long num_avengers(long long i, long long j) {
    auto upper = upper_bound(a.begin(), a.end(), j);
    auto lower = lower_bound(a.begin(), a.end(), i);

    long long count = upper - lower;

    return count;
}

long long solve(long long i, long long j) {
    long long ans = B*num_avengers(i, j)*(j-i+1);

    //cout << i << ' ' << j << ' ' << num_avengers(i,j) << ' ' << ans << '\n';

    if(ans == 0) {
        return A;
    }
    if(i == j) {
        return ans;
    }

    return min(solve(i, (i+j)/2) + solve((i+j)/2 + 1, j), ans);
}

int main() {
    long long input;
    cin >> n >> k >> A >> B;

    for(long long i = 0; i < k; ++i) {
        cin >> input;
        a.push_back(input-1);
    }

    sort(a.begin(), a.end());

    cout << solve(0, pow(2,n)-1) << '\n';

    return 0;
}