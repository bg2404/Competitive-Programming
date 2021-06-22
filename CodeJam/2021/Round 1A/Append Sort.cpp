#include <bits/stdc++.h>

using namespace std;

ostream& operator<<(ostream& os, vector<int> &a) {
    for(int d: a) {
        os << d;
    }
    return os;
}

int solve(vector<int> a, vector<int> &b) {
    int na = a.size(), nb = b.size();
    if (na < nb) {
        return 0;
    } else if (na == nb) {
        if (a < b) {
            return 0;
        } else {
            b.push_back(0);
            return 1;
        }
    } else {
        int op = 1;
        for (int i = 0; i < nb; ++i) {
            if (a[i] < b[i]) {
                op = 2;
                break;
            } else if (a[i] > b[i]) {
                op = 3;
                break;
            }
        }
        if (op == 1) {
            op = 3;
            for (int i = nb; i < na; ++i) {
                if (a[i] != 9) {
                    op = 1;
                    break;
                }
            }
        }
        if (op == 1) {
            b = a;
            for (int i = na - 1; i >= 0; --i) {
                ++b[i];
                if (b[i] == 10) {
                    b[i] = 0;
                } else {
                    break;
                }
            }
            return na - nb;
        } else if (op == 2) {
            while (b.size() < a.size()) {
                b.push_back(0);
            }
            return na - nb;
        } else if (op == 3) {
            while (b.size() <= a.size()) {
                b.push_back(0);
            }
            return na + 1 - nb;
        }
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n = 2;
        cin >> n;
        vector<vector<int> > x(n);
        for (int i = 0; i < n; ++i) {
            vector<int> d;
            int num;
            cin >> num;
            while (num) {
                d.push_back(num % 10);
                num /= 10;
            }
            reverse(d.begin(), d.end());
            x[i] = d;
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            int d = solve(x[i - 1], x[i]);
            // cout << '(' << d << ", " << x[i] << ") ";
            ans += d;
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
}