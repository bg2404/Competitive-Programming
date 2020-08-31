#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int max(int a, int b) {
    if(a > b) {
        return a;
    }
    return b;
}

int min(int a, int b) {
    if(a > b) {
        return b;
    }
    return a;
}

int s;
vector<int> factors;
int ans = 10000000000000000;
int d;
int get_ans(int a, int b, int i) {
    if(i >= s) {
        d = max(a,b);
    } else {
        d = min(get_ans(a*factors[i], b, i+1), get_ans(a, b*factors[i], i + 1));
    }
    ans = min(d, ans);
    return ans;
}
int32_t main() {
    int x, y;
    cin >> x;
    y = x;
    int i = 3;
    int num = 1;
    while(!(x&1)) {
        x /= 2;
        num *= 2;
    }
    factors.push_back(1);
    factors.push_back(num);
    while(x > 1 && i <= 1000000) {
        num = 1;
        if(x % i == 0) {
            while(x % i == 0) {
                x /= i;
                num *= i;
            }
            factors.push_back(num);
        }
        i += 2;
    }
    if(x > 1) {
        factors.push_back(x);
    }

    s = factors.size();

    // cout << s << '\n';

    // for(int i = 0; i < s; ++i) {
    //     cout << factors[i] << ' ';
    // }
    // cout << '\n';

    int ans = get_ans(1, 1, 0);

    d = y / ans;

    cout << d << ' ' << ans << '\n';

    return 0;
}