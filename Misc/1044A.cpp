#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v;
    vector<int> h;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int maxx2 = 0;
    for(int i = 0; i < m; ++i) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if(x1 == 1) {
            h.push_back(x2);
        }
    }

    sort(v.begin(), v.end());
    sort(h.begin(), h.end());
    v.push_back(1000000000);

    int i, j, ans = h.size();
    for(i = 0; i < v.size(); ++i) {
        while(j < h.size() && h[j] < v[i]) {
            ++j;
        }
        ans = min(ans, i + (int)h.size() - j);
    }

    cout << ans << '\n';

    return 0;
}