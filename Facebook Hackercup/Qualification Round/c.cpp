#include<bits/stdc++.h>
#define pos first
#define height second

using namespace std;

void solve(int T) {
    int n;
    cin >> n;
    vector<pair<int, int> > tree(n);
    for(int i = 0; i < n; ++i) {
        cin >> tree[i].pos >> tree[i].height;
    }
    sort(tree.begin(), tree.end());
    set<int> st;
    map<int, int> mp;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        // cout << i << '\n';
        pair<int, int> cut[2] = { {tree[i].pos, tree[i].height}, {tree[i].pos+tree[i].height, tree[i].height} };
        for(int j = 1; j > -1; --j) {
            int r = cut[j].first;
            int len = cut[j].second;
            int l = r - len;
            // cout << l << ' ' << r << ' ' << len << ' ';
            if(st.count(l)) {
                int old_len = mp[l];
                ans = max(ans, old_len + len);
                if(st.count(r)) {
                    mp[r] = max(mp[r], len + old_len);
                } else {
                    st.insert(r);
                    mp[r] = old_len + len;
                }
            } else {
                ans = max(ans, len);
                if(st.count(r)) {
                    mp[r] = max(mp[r], len);
                } else {
                    st.insert(r);
                    mp[r] = len;
                }
            }
            // cout << ans << '\n';
        }
    }
    cout << "Case #" << T << ": ";
    cout << ans << '\n';
}

int main() {
    freopen("c.txt", "r", stdin);
    freopen("cout.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}