#include <bits/stdc++.h>

using namespace std;

void ask_query(int n) {
    cout << "? " << n << endl;
}

int main() {
    int n, start, x;
    cin >> n >> start >> x;
    srand(n + start + x);
    vector<int> idx;
    for (int i = 1; i <= n; ++i) {
        idx.push_back(i);
    }
    swap(idx[0], idx[start - 1]);
    for (int i = 1; i < n; ++i) {
        swap(idx[i], idx[(rand() % (n - 1)) + 1]);
    }
    int ans = -1, value, next, prev = -1, pnext;
    for (int i = 0; i < min(1000, n); ++i) {
        ask_query(idx[i]);
        cin >> value >> next;
        if (value >= x) {
            if (ans == -1) {
                ans = value;
            } else {
                ans = min(ans, value);
            }
        } else {
            if (prev == -1 || prev < value) {
                prev = value;
                pnext = next;
            }
        }
    }
    int num = 999;
    while (num-- && pnext > 0) {
        ask_query(pnext);
        cin >> value >> pnext;
        if (value >= x) {
            if (ans == -1) {
                ans = value;
            } else {
                ans = min(ans, value);
            }
            break;
        }
    }
    cout << "! " << ans << endl;
    return 0;
}