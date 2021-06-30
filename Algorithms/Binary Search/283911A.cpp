#include<bits/stdc++.h>

using namespace std;

bool search(vector<int> &a, int k) {
    if(a.empty()) {
        return false;
    }
    int l = 0, r = a.size() - 1, m;
    while(l <= r) {
        m = l + r >> 1;
        if(a[m] == k) {
            return true;
        } else if(a[m] < k) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return false;
}

int main() {
    int n, k, q;
    cin >> n >> k;
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
    }
    while(k--) {
        cin >> q;
        if(search(a, q)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}