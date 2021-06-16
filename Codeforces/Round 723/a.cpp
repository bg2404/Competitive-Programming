#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + n);
        for (int &i : a) {
            cin >> i;
        }
        sort(a.begin(), a.end());
        for (int i = 2; i < 2 * n; i += 2) {
            swap(a[i], a[i - 1]);
        }
        for(int i: a) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}