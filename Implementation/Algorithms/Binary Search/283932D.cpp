#include<bits/stdc++.h>

using namespace std;

struct assistant {
    int t;
    int z;
    int y;
};

bool isFeasible(vector<assistant> &a, int m, int t) {
    int cnt = 0;
    for(auto i: a) {
        int n = t / (i.t * i.z + i.y);
        int r = t % (i.t * i.z + i.y);
        cnt += n * i.z + min(i.z, r / i.t);
        // cout << cnt << ' ';
    }
    // cout << "(" << cnt << ", " << t << ") ";
    return cnt >= m;
}

int solve(vector<assistant> &a, int m) {
    int l = 0, r = 2000000, ans = r, mid;
    while(l <= r) {
        mid = l + r >> 1;
        if(isFeasible(a, m, mid)) {
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<assistant> a(n);
    for(auto &i: a) {
        cin >> i.t >> i.z >> i.y;
    }
    int t = solve(a, m);
    cout << t << '\n';
    for(auto i: a) {
        int num = t / (i.t * i.z + i.y);
        int r = t % (i.t * i.z + i.y);
        int cnt = num * i.z + min(i.z, r / i.t);
        cout << min(cnt, m) << ' ';
        m -= min(cnt, m);
    }

    return 0;
}