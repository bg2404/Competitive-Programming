#include <bits/stdc++.h>

using namespace std;

int query(int a, int b, int c) {
    cout << a << ' ' << b << ' ' << c << endl;
    int m;
    cin >> m;
    return m;
}

void median_sort(vector<int> &a) {
    int n = a.size();
    if (n < 3) {
        return;
    }
    int x = a[0];
    int y = a[1];
    vector<int> l[3];
    for (int i = 2, j; i < n; ++i) {
        int m = query(x, y, a[i]);
        if (m == x) {
            j = 0;
        } else if (m == a[i]) {
            j = 1;
        } else {
            j = 2;
        }
        l[j].push_back(a[i]);
    }
    median_sort(l[0]);
    int len = l[0].size();
    if (len > 1) {
        int m = query(l[0][0], l[0][1], x);
        if (m == l[0][0]) {
            reverse(l[0].begin(), l[0].end());
        }
    }
    for (int i = 1; i < 3; ++i) {
        median_sort(l[i]);
        len = l[i].size();
        if (len > 1) {
            int m = query(x, l[i][0], l[i][1]);
            if (m == l[i][1]) {
                reverse(l[i].begin(), l[i].end());
            }
        }
    }
    a.clear();
    a.insert(a.end(), l[0].begin(), l[0].end());
    a.push_back(x);
    a.insert(a.end(), l[1].begin(), l[1].end());
    a.push_back(y);
    a.insert(a.end(), l[2].begin(), l[2].end());
}

int main() {
    int T, N, Q;
    cin >> T >> N >> Q;
    vector<int> a;
    for (int i = 1; i <= N; ++i) {
        a.push_back(i);
    }
    for (int t = 1; t <= T; ++t) {
        vector<int> temp = a;
        median_sort(temp);
        for (int x : temp) {
            cout << x << ' ';
        }
        cout << endl;
        int m;
        cin >> m;
    }
    return 0;
}