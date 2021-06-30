#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(1, 1);
        int sum = 1;
        while (sum < n) {
            v.push_back(v.back() << 1);
            sum += v.back();
        }
        if (sum > n) {
            v.back() = n + 1 - v.back();
            int i = (int)v.size() - 2;
            while (i >= 0) {
                if (v[i] > v[i + 1]) {
                    swap(v[i], v[i + 1]);
                    --i;
                } else {
                    break;
                }
            }
        }
        for(int i = (int)v.size()-2; i >= 0; --i) {
            v[i+1] -= v[i];
        }
        cout << (int)v.size() - 1 << endl;
        for(int i = 1; i < v.size(); ++i) {
            cout << v[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}