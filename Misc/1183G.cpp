#include<bits/stdc++.h>

using namespace std;

bool comparator(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first || (a.first == b.first && a.second > b.second);
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > c(n), t(n, {0, 0});
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &c[i].first, &c[i].second);
        ++t[c[i].first-1].first;
        if(c[i].second) {
            ++t[c[i].first-1].second;
        }
    }
    sort(t.begin(), t.end(), comparator);
    int a1 = t[0].first, a2 = t[0].second, ra = t[0].first-1, rf = 0;
    for(int i = 0; i < n; ++i) {
        if(ra <= t[i].first) {
            rf = max(rf, )
        } else {
            rf = max(rf, )
        }
    }
    printf("%d %d\n", a1, a2);

}

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        solve();
    }
    return 0;
}