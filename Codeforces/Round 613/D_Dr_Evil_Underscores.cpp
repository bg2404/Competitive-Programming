#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int solve(vector<int> a, int b) {
    if(b < 0 || a.size() == 0) {
        return 0;
    }

    vector<int> z, o;

    for(auto & i : a) {
        if((i >> b) & 1) {
            o.push_back(i);
        } else {
            z.push_back(i);
        }
    }

    if(o.size() == 0) return solve(z, b - 1);
    else if(z.size() == 0) return solve(o, b - 1);
    else return min(solve(o, b-1), solve(z, b-1)) + (1 << b);
}

int32_t main() {
    int n; 
    cin >> n;
    vector<int> a(n);
    int num = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        num = max(num, a[i]);
    }

    int b = log2(num) + 1;

    cout << solve(a, b);

    return 0;
}