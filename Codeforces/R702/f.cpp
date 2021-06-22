#include <iostream>
#include <map>
#include <vector>

using namespace std;

int getNum(vector<int> &cnt, int m) {
    int ans = 0;
    for (unsigned int i = 0; i < cnt.size(); ++i) {
        if (cnt[i] < m) {
            ans += cnt[i];
        } else {
            ans += cnt[i] - m;
        }
    }
    return ans;
}

int binary_search(vector<int> &cnt, int n) {
    int ans = n, l = 0, r = n, m;
    while (l <= r) {
        m = (l + r) >> 1;
        int al = getNum(cnt, m - 1);
        int am = getNum(cnt, m);
        int ar = getNum(cnt, m + 1);
        ans = min(ans, am);
        if (al >= am && am <= ar) {
            return am;
        } else if (al <= am && am <= ar) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, int> cnt_map;
        for (int i : a) {
            cnt_map[i] = cnt_map[i] + 1;
        }
        vector<int> cnt;
        for (pair<int, int> p : cnt_map) {
            cnt.push_back(p.second);
        }
        int ans = binary_search(cnt, n);
        cout << ans << '\n';
    }
    return 0;
}