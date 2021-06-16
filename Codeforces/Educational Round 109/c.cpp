#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    cout << "[ ";
    for (T e : v) {
        cout << e << ' ';
    }
    cout << ']';
    return os;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve(vector<int> &v, vector<int> &x, vector<char> &d, vector<int> &ans, int m) {
    if (v.empty()) {
        return;
    }
    stack<int> q;
    for (int i = 0; i < v.size(); ++i) {
        if (q.empty()) {
            q.push(v[i]);
        } else {
            if (d[q.top()] == 'L') {
                if (d[v[i]] == 'L') {
                    ans[v[i]] = ans[q.top()] = (x[v[i]] + x[q.top()]) / 2;
                    q.pop();
                } else {
                    q.push(v[i]);
                }
            } else {
                if (d[v[i]] == 'L') {
                    ans[v[i]] = ans[q.top()] = (x[v[i]] - x[q.top()]) / 2;
                    q.pop();
                } else {
                    q.push(v[i]);
                }
            }
        }
    }
    while (q.size() > 1) {
        int e1 = q.top();
        q.pop();
        int e2 = q.top();
        q.pop();
        if (d[e1] == 'R' && d[e2] == 'R') {
            ans[e1] = ans[e2] = m - (x[e1] + x[e2]) / 2;
        } else {
            ans[e1] = ans[e2] = m - (x[e1] - x[e2]) / 2;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n), e, o;
        vector<char> d(n), d2(n);
        map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
            pos[x[i]] = i;
        }
        sort(x.begin(), x.end());
        for (int i = 0; i < n; ++i) {
            if (x[i] & 1) {
                o.push_back(i);
            } else {
                e.push_back(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }
        for (int i = 0; i < n; ++i) {
            d2[i] = d[pos[x[i]]];
        }
        vector<int> tempAns(n, -1), ans(n);
        solve(o, x, d2, tempAns, m);
        solve(e, x, d2, tempAns, m);
        for (int i = 0; i < n; ++i) {
            ans[pos[x[i]]] = tempAns[i];
        }
        for (int e : ans) {
            cout << e << ' ';
        }
        cout << endl;
    }
    return 0;
}