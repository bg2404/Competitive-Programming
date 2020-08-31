#include<bits/stdc++.h>

using namespace std;

int get_b(int i, int n) {
    int a1, a2;
    cout << "? " << i << endl;
    cin >> a1;
    int x = i + n / 2;
    if(x > n) {
        x -= n;
    }
    cout << "? " << x << endl;
    cin >> a2;
    return a1 - a2;
}

int bins(int l, int r, int a, int b, int n) {
    if(a < b) {
        while(l < r) {
            int m = (l + r) / 2;
            int bm = get_b(m, n);
            if(bm == 0) {
                return m;
            } else if(bm < 0) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    } else {
        while(l < r) {
            int m = (l + r) / 2;
            int bm = get_b(m, n);
            if(bm == 0) {
                return m;
            } else if(bm < 0) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
    }
    if(l == r) {
        int b = get_b(l, n);
        if(b == 0) {
            return l;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int b0 = get_b(1, n), bn_2 = -b0;
    if(b0 & 1) {
        cout << "! -1" << endl;
        return 0;
    }
    if(b0 == 0) {
        cout << "! 1" << endl;
        return 0;
    }
    int ans = bins(1, 1 + n / 2, b0, bn_2, n);
    cout << "! " << ans << endl;
    return 0;
}