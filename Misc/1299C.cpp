#include<bits/stdc++.h>

using namespace std;

inline double average(long long n, int d) {
    return (((double)n)/d);
}
inline double average(pair<long long, int> p) {
    return average(p.first, p.second);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i: a) {
        cin >> i;
    }
    stack<pair<long long, int> > avg;
    for(int i = 0; i < n; ++i) {
        long long sum = a[i];
        int cnt = 1;
        while(!avg.empty() && average(sum, cnt) <= average(avg.top())) {
            sum += avg.top().first;
            cnt += avg.top().second;
            avg.pop();
        }
        avg.push({sum, cnt});
    }
    vector<double> ans(n);
    int i = n - 1;
    while(!avg.empty()) {
        pair<long long, int> top = avg.top();
        avg.pop();
        double cavg = average(top);
        int cnt = top.second;
        while(cnt--) {
            ans[i--] = cavg;
        }
    }
    for(int i = 0; i < n; ++i) {
        cout << fixed << setprecision(12) << ans[i] << ' ';
    }
    cout << '\n';
}