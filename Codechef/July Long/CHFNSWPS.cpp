#include<bits/stdc++.h>

using namespace std;

vector<int> a, b;
map<int, int> cnt, acnt, bcnt;
set<pair<int, int> > ax, bx;

void solve() {
    int n;
    cin >> n;
    a = b = vector<int>(n);
    cnt.clear();
    acnt.clear();
    bcnt.clear();

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
        ++acnt[a[i]];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
        ++cnt[b[i]];
        ++bcnt[b[i]];
    }

    int gmin = cnt.begin()->first;

    ax.clear();
    bx.clear();
    for(auto p: cnt) {
        int k = p.first, v = p.second;
        if(v & 1) {
            cout << "-1\n";
            return;
        }
        if(acnt[k] > v/2) {
            ax.insert({k, acnt[k] - v/2});
        }
        if(bcnt[k] > v/2) {
            bx.insert({k, bcnt[k] - v/2});
        }
    }

    long long ans = 0;

    while(ax.size()) {
        pair<int, int> ap = *ax.begin();
        pair<int, int> bp = *bx.begin();
        if(ap.first < bp.first) {
            if(2*gmin < ap.first) {
                ans += 2*gmin;
            } else {
                ans += ap.first;
            }
            pair<int, int> bp = *bx.rbegin();
            ax.erase(ap);
            bx.erase(bp);
            if(ap.second > 1) {
                ax.insert({ap.first, ap.second - 1});
            }
            if(bp.second > 1) {
                bx.insert({bp.first, bp.second - 1});
            }
        } else {
            if(2*gmin < bp.first) {
                ans += 2*gmin;
            } else {
                ans += bp.first;
            }
            pair<int, int> ap = *ax.rbegin();
            ax.erase(ap);
            bx.erase(bp);
            if(ap.second > 1) {
                ax.insert({ap.first, ap.second - 1});
            }
            if(bp.second > 1) {
                bx.insert({bp.first, bp.second - 1});
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}