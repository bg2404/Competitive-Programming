#include<bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &i: a) {
        cin >> i;
    }
    if(n == 1) {
        cout << a[0] - 1 << '\n';
        return 0;
    }
    sort(a.begin(), a.end());

    long long min_cost = 1000000000000000000LL, cost, cur = 1, num;
    do {
        num = 1;
        cost = 0;
        for(int i = 0; i < n; ++i) {
            cost += abs(num - a[i]);
            num *= cur;
        }
        num /= cur;
        min_cost = min(min_cost, cost);
        cur++;
    } while(num <= a.back()*10);
    cout << min_cost << '\n';

    return 0;
}