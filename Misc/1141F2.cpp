#include<bits/stdc++.h>

using namespace std;

vector<int> a, p;
map<int, vector<pair<int, int> > > mp;
int main() {
    int n;
    cin >> n;
    a = p = vector<int> (n+1);
    a[0] = p[0] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i-1] + a[i];
    }
    for(int i = 1; i <= n; ++i) {
        for(int l = 0; l + i <= n; ++l) {
            int r = l + i;
            int bs = p[r] - p[l];
            if(mp.count(bs)) {
                mp[bs].push_back({r, l+1});
            } else {
                mp.insert({bs, { {r, l+1} } });
            }
        }
    }
    int ansl = 0;
    vector<pair<int, int> > ansv;
    for(auto p: mp) {
        // cout << p.first << ' ';
        vector<pair<int, int> > bv = p.second;
        sort(bv.begin(), bv.end());
        // for(auto p: bv) {
        //     cout << "(" << p.second << "," << p.first << ") ";
        // }
        // cout << '\n';
        int end = bv[0].first;
        int cnt = 1;
        vector<pair<int, int> > blocks;
        blocks.push_back(bv[0]);
        for(int i = 1; i < bv.size(); ++i) {
            if(bv[i].second > end) {
                ++cnt;
                blocks.push_back(bv[i]);
                end = bv[i].first;
            }
        }
        if(cnt > ansl) {
            ansl = cnt;
            ansv = blocks;
        }
    }
    cout << ansl << '\n';
    for(auto b: ansv) {
        cout << b.second << ' ' << b.first << '\n';
    }
    return 0;
}