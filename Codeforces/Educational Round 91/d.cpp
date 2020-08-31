#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, x, k ,y;
    cin >> n >> m;
    cin >> x >> k >> y;
    vector<int> a(n+2), b(m);
    a[0] = a[n+1] = -1;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int &i: b) {
        cin >> i;
    }
    if(m > n) {
        cout << -1 << '\n';
        return;
    }
    int l = 0, r = 1;
    long long mana = 0;
    for(int i = 0; i < m; ++i) {
        while(r <= n) {
            if(a[r] != b[i]) {
                ++r;
            } else {
                break;
            }
        }
        // cout << b[i] << ' ' << a[l] << ' ' << a[r] << ' ';
        if(r > n) {
            cout << -1 << '\n';
            return;
        }
        int len = r - l - 1;
        // cout << len << ' ';
        if(len == 0) {
            l = r++;
            // cout << '\n';
            continue;
        }
        int lb = a[l], ub = a[r], mp = *max_element(a.begin() + l + 1, a.begin() + r);
        if(len % k == 0) {
            int q = len / k;
            if(x <= k*y) {
                mana += (x*(long long)q);
            } else {
                if(max(lb, ub) >= mp) {
                    mana += (len*(long long)y);
                } else {
                    mana += (((len-k)*(long long)y) + x);
                }
            }
        } else {
            if(len < k) {
                if(max(ub, lb) < mp) {
                    cout << -1 << '\n';
                    return;
                } else {
                    mana += (len*(long long)y);
                }
            } else {
                mana += ((len%k)*(long long)y);
                len = len - len%k;
                int q = len / k;
                if(x <= k*y) {
                    mana += (x*(long long)q);
                } else {
                    if(max(lb, ub) >= mp) {
                        mana += (len*(long long)y);
                    } else {
                        mana += (((len-k)*(long long)y) + x);
                    }
                }
            }
        }
        // cout << mana << '\n';
        l = r++;
    }
    if(r <= n) {
        r = n + 1;
        int len = r - l - 1;
        int lb = a[l], ub = a[r], mp = *max_element(a.begin() + l + 1, a.begin() + r);
        if(len % k == 0) {
            int q = len / k;
            if(x <= k*y) {
                mana += (x*(long long)q);
            } else {
                if(max(lb, ub) >= mp) {
                    mana += (len*(long long)y);
                } else {
                    mana += (((len-k)*(long long)y) + x);
                }
            }
        } else {
            if(len < k) {
                if(max(ub, lb) < mp) {
                    cout << -1 << '\n';
                    return;
                } else {
                    mana += (len*(long long)y);
                }
            } else {
                mana += ((len%k)*(long long)y);
                len = len - len%k;
                int q = len / k;
                if(x <= k*y) {
                    mana += (x*(long long)q);
                } else {
                    if(max(lb, ub) >= mp) {
                        mana += (len*(long long)y);
                    } else {
                        mana += (((len-k)*(long long)y) + x);
                    }
                }
            }
        }
    }
    cout << mana << '\n';
}

int main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}